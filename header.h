using namespace std;

int s_int(){
    while(true){
        try{
            int x;
            cin>>x;
            return x;
        }
        catch(const ios::failure&){
        cin.clear();
        string kld;
        getline(cin, kld);
        cout<<"Klaida: iveskite skaiciu"<<endl;
        }
    }
}

double s_double(){
    while(true){
        try{
            double x;
            cin>>x;
            return x;
        }
        catch (const ios::failure&){
            cin.clear();
            string kld;
            getline(cin, kld);
            cout<<"Klaida: iveskite skaiciu"<<endl;
        }
    }

}

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

void spausdinti_lentele(const vector<stud>& A, int pas){
    ofstream kiet("kietekai.txt");
    ofstream varg("vargsiukai.txt");
    if(pas=1){
        cout<<endl<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Vardas"<<right<<setw(20)<<"Galutinis (Vid.)"<<right<<setw(20)<<"Galutinis (Med.)"<<endl;

        cout<<string(70, '-')<<endl;

        for(const auto &s : A){
            cout<<left<<setw(15)<<s.pavarde<<left<<setw(15)<<s.vardas<<right<<setw(20)<<fixed<<setprecision(2)<<s.vid<<right<<setw(20)<<fixed<<setprecision(2)<<s.med<<endl;
        }
    }
    if(pas=2){
            kiet<<"Pavarde"<<left<<setw(15)<<"Vardas"<<right<<setw(20)<<"Galutinis (Vid.)"<<right<<setw(20)<<"Galutinis (Med.)"<<endl<<string(70, '-')<<endl;
            varg<<"Pavarde"<<left<<setw(15)<<"Vardas"<<right<<setw(20)<<"Galutinis (Vid.)"<<right<<setw(20)<<"Galutinis (Med.)"<<endl<<string(70, '-')<<endl;

            for(const auto &s : A){
                if(s.vid >= 5){
                    kiet<<s.pavarde<<left<<setw(15)<<s.vardas<<right<<setw(20)<<fixed<<setprecision(2)<<s.vid<<right<<setw(20)<<fixed<<setprecision(2)<<s.med<<endl;
                }
                else {
                    varg<<s.pavarde<<left<<setw(15)<<s.vardas<<right<<setw(20)<<fixed<<setprecision(2)<<s.vid<<right<<setw(20)<<fixed<<setprecision(2)<<s.med<<endl;
                }
            }

    }
    if(pas=3){

    }

}

void generuoti_studentus(int kiekismok, int kiekpaz) {
    ofstream is("kursiokai.txt");

    is<<left<<" "<<"Vardas"<<" "<<"Pavarde";
    for(int i=1; i<=kiekpaz; i++){
        is<<" "<<("ND" + to_string(i));

    }
    is<<" "<<"Egz."<<endl;

    static bool ijungtas = false;
    if(!ijungtas){
        srand(time(0));
        ijungtas = true;
    }
    for(int i=1; i<=kiekismok; ++i){
        string vardas = "Vardas" + to_string(i);
        string pavarde = "Pavarde" + to_string(i);
        is << vardas << " " << pavarde;
        for (int j=0; j<kiekpaz; ++j){
        int pazymys = atsitiktinis();
        is << " "<<pazymys;
        }
        is<<endl;
    }


    int egz = atsitiktinis();
    is << " "<<egz<<endl;

    is.close();

}
