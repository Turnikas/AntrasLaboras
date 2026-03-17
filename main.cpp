#include <iostream>
#include <string>
using namespace std;

int main()
{
    string vardai[100];
    int pazymiai[100][10];
    int pazymiuKiekis[100];
    int mokiniuKiekis = 0;
    char pasirinkimas;

    while (true) {
        cout << "\n========== MOKINIU PAZYMIU SISTEMA ==========\n";
        cout << "1. Prideti mokini ir jo pazymius\n";
        cout << "2. Perziureti visus mokinius ir pazymius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti mokinio pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "6. Iseiti\n";
        cout << "Pasirinkite veiksma\n> ";
        cin >> pasirinkimas;
//-------------------------1-------------------------------
        switch (pasirinkimas) {
            case '1':
                if (mokiniuKiekis>=100) {
                    cout <<"Siuo metu sistemoje yra per daug mokiniu.";
                    break;
                }
                cout <<"Iveskite mokinio varda:\n> ";
                cin >> vardai[mokiniuKiekis];

                cout <<"Kiek pazymiu norite ivesti? (Min 1)(Max 10)\n> ";
                cin >> pazymiuKiekis[mokiniuKiekis];

                while (pazymiuKiekis[mokiniuKiekis] > 10 or pazymiuKiekis[mokiniuKiekis] < 1) {
                    cout << "Ivesta per daug arba per mazai pazymiu.\nKiek pazymiu norite ivesti? (Min 1)(Max 10)\n> ";
                    cin >> pazymiuKiekis[mokiniuKiekis];
                }

                for (int i=0; i<pazymiuKiekis[mokiniuKiekis]; i++) {
                    cout << "Pazymys " << i + 1 << ": ";
                    cin >> pazymiai[mokiniuKiekis][i];
                }
                cout << "Mokinio pazymiai ivesti sekmingai.\n";
                mokiniuKiekis++; //padidinam +1
                break;
//-----------------------2------------------------
            case '2':
            {
                if (mokiniuKiekis == 0) {
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

            default:
                cout << "Blogas pasirinkimas.\n";
                break;
        }
    }

    return 0;
}