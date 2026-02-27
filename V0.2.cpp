#include <bits/stdc++.h>
using namespace std;

struct stud {
    string vardas;
    string pavarde;
    vector<double> tarp;
    double egz;
    double vid;
    double med;
};

double atsitiktinis() {
    return rand()%11;
}

void skaiciuoti(stud &s) {
    double sum=s.egz;
    for (double x:s.tarp) sum += x;
    s.vid=sum/(s.tarp.size()+1);

    sort(s.tarp.begin(), s.tarp.end());
    int d=s.tarp.size();
    if (d%2==0)
        s.med=(s.tarp[d/2]+s.tarp[d/2-1])/2.0;
    else
        s.med=s.tarp[d/2];
}

void spausdinti_lentele(const vector<stud>& A){
    cout<<endl<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Vardas"<<right<<setw(20)<<"Galutinis (Vid.)"<<right<<setw(20)<<"Galutinis (Med.)"<<endl;

    cout<<string(70, '-')<<endl;

    for(const auto &s : A){
        cout<<left<<setw(15)<<s.pavarde<<left<<setw(15)<<s.vardas<<right<<setw(20)<<fixed<<setprecision(2)<<s.vid<<right<<setw(20)<<fixed<<setprecision(2)<<s.med<<endl;
    }
}


int main() {
    srand(time(NULL));
    vector<stud> A;

    while (true) {
        cout<<"1-Rankinis studentu ivedimas"<<endl;
        cout<<"2-Generuoti tik pazymius"<<endl;
        cout<<"3-Generuoti vardus, pavardes ir pazymius"<<endl;
        cout<<"4-Skaityti is failo"<<endl;
        cout<<"5-Baigti darba"<<endl;
        cout<<"Pasirinkite:"<<endl;

        int pasirinkimas;

        if(!(cin>>pasirinkimas)){
            cin.clear();
            string kintamasis;
            getline(cin, kintamasis);
            cout<<"Ivedete neteisingo tipo duomeni. Bandykite dar karta"<<endl;
            continue;
        }


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
                double x;
                cin>>x;
                if (x<0) break;
                s.tarp.push_back(x);
            }

            cout<<"Egzamino rezultatas: "<<endl;
            cin>>s.egz;

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

        }

        else {
            cout<<"Neteisingas pasirinkimas"<<endl;
        }
    }

    spausdinti_lentele(A);

    return 0;
}
