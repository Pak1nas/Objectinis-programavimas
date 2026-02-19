#include <bits/stdc++.h>

using namespace std;

struct stud {
    string vardas;
    string pavarde;
    double* tarp;
    int nd_kiek;
    double egz;
    double vid;
    double med;
};

double atsitiktinis() {
    return rand()%11;
}

void skaiciuoti(stud &s) {
    double sum=s.egz;
    for (int i=0; i<s.nd_kiek; i++) sum+=s.tarp[i];
    s.vid=sum/(s.nd_kiek+1);

    sort(s.tarp, s.tarp+s.nd_kiek);
    if (s.nd_kiek%2==0)
        s.med=(s.tarp[s.nd_kiek/2]+s.tarp[s.nd_kiek/2 - 1])/2.0;
    else
        s.med=s.tarp[s.nd_kiek/2];
}

int main() {
    srand(time(NULL));

    stud*A=nullptr;
    int m=0;
    while (true) {
        cout<<"1-Rankinis studentu ivedimas"<<endl;
        cout<<"2-Generuoti tik pazymius"<<endl;
        cout<<"3-Generuoti vardus, pavardes ir pazymius"<<endl;
        cout<<"4-Baigti darba"<<endl;
        cout<<"Pasirinkite:"<<endl;

        int pasirinkimas;
        cin>>pasirinkimas;

        if (pasirinkimas==4)
            break;

        stud*temp=new stud[m + 1];
        for (int i=0; i<m; i++) temp[i]=A[i];
        delete[] A;
        A=temp;

        stud &s=A[m];
        s.tarp=nullptr;
        s.nd_kiek=0;

        if (pasirinkimas==1) {
            cout<<"Iveskite varda ir pavarde:"<<endl;
            cin>>s.vardas>>s.pavarde;

            cout<<"Iveskite ND (neigiamas baigia):"<<endl;
            while (true) {
                double x;
                cin>>x;
                if (x<0) break;

                double* t2=new double[s.nd_kiek + 1];
                for (int i=0; i<s.nd_kiek; i++) t2[i]=s.tarp[i];
                t2[s.nd_kiek]=x;

                delete[] s.tarp;
                s.tarp=t2;
                s.nd_kiek++;
            }

            cout<<"Egzamino rezultatas:"<<endl;
            cin>>s.egz;
        }

        else if (pasirinkimas == 2) {
            cout<<"Iveskite varda ir pavarde:"<<endl;
            cin>>s.vardas>>s.pavarde;

            int nd;
            cout<<"Kiek generuoti ND?";
            cin>>nd;

            s.tarp=new double[nd];
            s.nd_kiek=nd;

            for (int i=0; i<nd; i++) s.tarp[i]=atsitiktinis();
            s.egz=atsitiktinis();
        }

        else if (pasirinkimas==3) {
            static string vardai[] = {"Mykolas","Darius","Motejus", "Nojus", "Jonas"};
            static string pavardes[] = {"Matulis","Navierauskas","Motejunas","Stankus","Mezetis"};

            s.vardas=vardai[rand()%5];
            s.pavarde=pavardes[rand()%5];

            int nd=rand()%7+3;
            s.tarp=new double[nd];
            s.nd_kiek=nd;

            for (int i=0; i<nd; i++) s.tarp[i]=atsitiktinis();
            s.egz=atsitiktinis();

            //cout<<"Sugeneruotas:"<<s.vardas<<" "<<s.pavarde<<endl;
        }

        skaiciuoti(s);
        m++;
    }

    cout<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Vardas"<<right<<setw(20)<<"Galutinis (Vid.)"<<right<<setw(20)<<"Galutinis (Med.)"<<endl;

    cout<<string(70, '-')<<endl;

    for (int i = 0; i<m; i++) {
        cout<<left<<setw(15)<<A[i].pavarde<<left<<setw(15)<<A[i].vardas<<right<<setw(20)<<fixed<<setprecision(2)<<A[i].vid<<right<<setw(20)<<fixed<<setprecision(2)<<A[i].med<<endl;
    }

    return 0;
}
