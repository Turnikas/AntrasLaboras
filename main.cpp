#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void linija()
{
    cout << "**************************************************\n";
}

int main()
{
    string vardai[100];
    int pazymiai[100][10];
    int pazymiuKiekis[100];
    int mokiniuKiekis = 0;
    char pasirinkimas;

    while (true) {
        linija();
        cout << "========== MOKINIU PAZYMIU SISTEMA ==========\n";
        cout << "1. Prideti mokini ir jo pazymius\n";
        cout << "2. Perziureti visus mokinius ir pazymius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti mokinio pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "6. Iseiti\n";
        linija();
        cout << "Pasirinkite veiksma\n> ";
        
        cin >> pasirinkimas;
        
//-------------------------1--------------------------------------------------------------------
        switch (pasirinkimas) {
            case '1':
                if (mokiniuKiekis>=100) {
                    linija();
                    cout <<"Siuo metu sistemoje yra per daug mokiniu.";
                    linija();
                    break;
                }
                cout <<"Iveskite mokinio varda:\n> ";
                cin >> vardai[mokiniuKiekis];

                cout <<"Kiek pazymiu norite ivesti? (Min 1)(Max 10)\n> ";
                cin >> pazymiuKiekis[mokiniuKiekis];

                while (pazymiuKiekis[mokiniuKiekis] > 10 || pazymiuKiekis[mokiniuKiekis] < 1) {
                    linija();
                    cout << "Ivesta per daug arba per mazai pazymiu.\n";
                    linija();
                    cout << "Kiek pazymiu norite ivesti? (Min 1)(Max 10)\n> ";
                    cin >> pazymiuKiekis[mokiniuKiekis];
                }

                for (int i=0; i<pazymiuKiekis[mokiniuKiekis]; i++) {
                    cout << "Pazymys " << i + 1 << ": ";
                    cin >> pazymiai[mokiniuKiekis][i];
					pazymiai[mokiniuKiekis][i] = abs(pazymiai[mokiniuKiekis][i]);
                }
                linija();
                cout << "Mokinio pazymiai ivesti sekmingai.\n";
                mokiniuKiekis++; //padidinam +1
                break;
//-----------------------2-------------------------------------------------------------
            case '2':
            {
                if (mokiniuKiekis == 0) {
                    linija();
                    cout << "Sistemoje nera mokiniu.\n";
                    break;
                }

                cout << "\n===== VISI MOKINIAI =====\n";

                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << ": ";

                    for (int j = 0; j < pazymiuKiekis[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }

                    cout << endl;
                }
                break;
            }
//-----------------------3--------------------------------------------------------------
            case '3':
            {
                if (mokiniuKiekis == 0) {
                    linija();
                    cout << "Sistemoje nera mokiniu.\n";
                    break;
                }

                cout << "\n===== MOKINIU SARASAS =====\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << endl;
                }

                int numeris;
                cout << "Iveskite mokinio numeri:\n> ";
                cin >> numeris;

                numeris = numeris - 1; // nes vartotojas mato nuo 1 o masyvas prasideda nuo 0

                if (numeris < 0 || numeris >= mokiniuKiekis) {
                    linija();
                    cout << "Tokio mokinio nera.\n";
                    break;
                }
                cout << "Mokinys: " << vardai[numeris] << endl;
                cout << "Pazymiai: ";

                for (int i = 0; i < pazymiuKiekis[numeris]; i++) {
                    cout << pazymiai[numeris][i] << " ";
                }

                cout << endl;
                break;
            }
  //-----------------------4-----------------------------------------------------
            case '4':
            {
                if (mokiniuKiekis == 0) {
                    linija();
                    cout << "Sistemoje nera mokiniu.\n";
                    break;
                }

                cout << "\n===== MOKINIU SARASAS =====\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << endl;
                }

                int numeris;
                cout << "Iveskite mokinio numeri:\n> ";
                cin >> numeris;

                numeris = numeris - 1;

                if (numeris < 0 || numeris >= mokiniuKiekis) {
                    linija();
                    cout << "Tokio mokinio nera.\n";
                    break;
                }

                cout << "Mokinys: " << vardai[numeris] << endl;

                if (pazymiuKiekis[numeris] == 0) {
                    linija();
                    cout << "Sis mokinys neturi pazymiu.\n";
                    break;
                }

                // Parodom pažymius su numeriais
                for (int i = 0; i < pazymiuKiekis[numeris]; i++) {
                    cout << i + 1 << ". " << pazymiai[numeris][i] << endl;
                }

                int indeksas;
                cout << "Kuri pazymi norite keisti?\n> ";
                cin >> indeksas;

                indeksas = indeksas - 1;

                if (indeksas < 0 || indeksas >= pazymiuKiekis[numeris]) {
                    linija();
                    cout << "Tokio pazymio nera.\n";
                    break;
                }

                int naujas;
                cout << "Iveskite nauja pazymi:\n> ";
                cin >> naujas;

                // Tikrinam kad 1–10
                if (naujas < 1 || naujas > 10) {
                    linija();
                    cout << "Blogas pazymys. Turi buti nuo 1 iki 10.\n";
                    break;
                }

                pazymiai[numeris][indeksas] = naujas;
                linija();
                cout << "Pazymys sekmingai atnaujintas.\n";
                break;
            }
   //-----------------------5--------------------------------------------------------------
            case '5':
            {
                if (mokiniuKiekis == 0) {
                    linija();
                    cout << "Sistemoje nera mokiniu.\n";
                    break;
                }

                cout << "\n===== MOKINIU SARASAS =====\n";
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << endl;
                }

                int numeris;
                cout << "Iveskite mokinio numeri, kuri norite pasalinti:\n> ";
                cin >> numeris;

                numeris = numeris - 1;

                if (numeris < 0 || numeris >= mokiniuKiekis) {
                    linija();
                    cout << "Tokio mokinio nera.\n";
                    break;
                }

                // shift'inam visus po jo
                for (int i = numeris; i < mokiniuKiekis - 1; i++) {
                    vardai[i] = vardai[i + 1];
                    pazymiuKiekis[i] = pazymiuKiekis[i + 1];

                    for (int j = 0; j < 10; j++) {
                        pazymiai[i][j] = pazymiai[i + 1][j];
                    }
                }

                mokiniuKiekis--;
                linija();
                cout << "Mokinys sekmingai pasalintas.\n";
                break;
            }
            case '6':
                linija();
                cout << "Aciu viso gero\n";
                linija();
                return 0;

            default:
                linija();
                cout << "Blogas pasirinkimas.\n";
                break;
        }
    }

    return 0;
}