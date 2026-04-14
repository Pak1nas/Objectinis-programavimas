#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <utility>
#include "header.h"

using namespace std;

int main() {

    srand(time(NULL));

    cin.exceptions(ios::failbit | ios::badbit);

    vector<stud> A;

    while (true) {
        cout<<"1-Rankinis studentu ivedimas"<<endl;
        cout<<"2-Generuoti tik pazymius"<<endl;
        cout<<"3-Generuoti vardus, pavardes ir pazymius"<<endl;
        cout<<"4-Skaityti is failo"<<endl;
        cout<<"5-Baigti darba"<<endl;
        cout<<"6-Generuoti mokiniu fila"<<endl;
        cout<<"Pasirinkite:"<<endl;

        int  pasirinkimas=s_int();

        if (pasirinkimas==5) {
            cout<<"Programa baigta."<<endl;
            break;
        }

        if (pasirinkimas==1) {
            stud s;
            cout<<"Iveskite varda ir tada pavarde:"<<endl;
            cin>>s.vardas >> s.pavarde;

            cout<<"Iveskite namu darbu rezultatus (neigiamas skaicius baigia):"<<endl;
            while (true) {
                double x=s_double();
                if(x<0) break;
                s.tarp.push_back(x);
            }

            cout<<"Egzamino rezultatas: "<<endl;
            s.egz=s_double();

            skaiciuoti(s);
            A.push_back(s);
        }

        else if (pasirinkimas==2) {
            stud s;
            cout<<"Iveskite varda ir pavarde: "<<endl;
            cin>>s.vardas >> s.pavarde;

            int nd;
            cout<<"Kiek generuoti namu darbu? "<<endl;
            cin>>nd;

            for (int i = 0; i<nd; i++)
            s.tarp.push_back(atsitiktinis());

            s.egz=atsitiktinis();

            skaiciuoti(s);
            A.push_back(s);
        }

        else if (pasirinkimas==3) {
            stud s;

            static vector<string>vardai={"Mykolas","Darius","Motejus", "Nojus", "Jonas"};
            static vector<string>pavardes={"Matulis","Navierauskas","Motejunas","Stankus","Mezetis"};

            s.vardas=vardai[rand()%vardai.size()];
            s.pavarde=pavardes[rand()%pavardes.size()];

            int nd = rand()%7+3;
            for (int i = 0; i<nd; i++)
                s.tarp.push_back(atsitiktinis());

            s.egz=atsitiktinis();

            skaiciuoti(s);
            A.push_back(s);

        }

        else if (pasirinkimas==4){

            ifstream duom("kursiokai.txt");
            if(!duom){
                cout<<"Nepavyko atidaryti failo"<<endl;
                continue;
            }

            string eil;

            if(!getline(duom, eil)){
                cout<<"Failas tuscias"<<endl;
                duom.close();
                continue;
            }

            bool header=false;
            for(char c : eil){
                if(isalpha(static_cast<unsigned char>(c))){
                    header=true;
                    break;
                }
            }
            if(!header){
                istringstream ars(eil);
                stud s;
                if(ars>>s.vardas>>s.pavarde){
                    vector<double>vals;
                    double v;
                    while(ars>>v) vals.push_back(v);
                    if(!vals.empty()){
                        s.egz=vals.back();
                        vals.pop_back();
                        s.tarp=std::move(vals);
                    }
                    skaiciuoti(s);
                    A.push_back(std::move(s));
                }
            }

            while(getline(duom, eil)){
                if(eil.find_first_not_of(" \t\r\n")==string::npos) continue;
                istringstream ars(eil);
                stud s;
                if(!(ars>>s.vardas>>s.pavarde)) continue;
                vector<double>vals;
                double v;
                while(ars>>v) vals.push_back(v);
                if(!vals.empty()){
                    s.egz=vals.back();
                    vals.pop_back();
                    s.tarp=std::move(vals);
                }
                skaiciuoti(s);
                A.push_back(std::move(s));
            }
            duom.close();
            cout<<"Faile buvo rasta: "<<A.size()<<" stundentu"<<endl;

        }
        else if(pasirinkimas==6){
            int moksk=0, pazsk=0;
            cout<<"Kiek mokiniu norite, kad butu file"<<endl;
            cin>>moksk;
            cout<<"Kiek norite kad butu pazymiu"<<endl;
            cin>>pazsk;
            generuoti_studentus(moksk, pazsk);
        }

        else {
            cout<<"Neteisingas pasirinkimas"<<endl;
        }
    }

    cout<<"1-Rusiavimas pagal varda"<<endl;
    cout<<"2-Rusiavimas pagal pavarde"<<endl;
    cout<<"3-Rusiavimas pagal galutini (vidurki)"<<endl;
    cout<<"4-Rusiavimas pagal galutini (mediana)"<<endl;
    cout<<"Pasirinkite 1"<<endl;

    int rus;
    if(!(cin>>rus)) rus=1;

    switch(rus){
    case 1:
        sort(A.begin(), A.end(),[](const stud &a, const stud &b){return a.vardas<b.vardas;});
        break;
    case 2:
        sort(A.begin(), A.end(), [](const stud &a, const stud &b){return a.pavarde<b.pavarde;});
        break;
    case 3:
        sort(A.begin(), A.end(), [](const stud &a, const stud &b){return a.vid>b.vid;});
        break;
    case 4:
        sort(A.begin(), A.end(), [](const stud &a, const stud &b){return a.med>b.med;});
        break;

    }

    cout<<"Kaip norite kad duomenys butu isvesti"<<endl;
    cout<<"1-tik ekrane"<<endl;
    cout<<"2-tik file"<<endl;
    cout<<"3-ekrane ir file"<<endl;
    cout<<"Pasirinkite 1"<<endl;

    int pas=0;
    cin>>pas;

    spausdinti_lentele(A, pas);

    return 0;
}
