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
