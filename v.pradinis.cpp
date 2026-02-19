#include <bits/stdc++.h>

using namespace std;

struct stud{
    string vardas;
    string pavarde;
    vector<double>tarp;
    double egz;
    double vid;
    double med;
};

int main()
{
    int n, m, knt, did=0;
    double sum=0, kntd=0;

    cin>>m;
    cin>>n;

    stud a[m];

    for(int i=0; i<m; i++){
         cin>>a[i].vardas>>a[i].pavarde;
        for(int j=0; j<n; j++){
            cin>>knt;
            a[i].tarp.push_back(knt);
            sum+=knt;
        }
        cin>>a[i].egz;
        sum+=a[i].egz;

        a[i].vid=sum/(n+1);

        sort(a[i].tarp.begin(), a[i].tarp.end());
        did=a[i].tarp.size();
        if(did%2==0){
            did=did/2;
            kntd=(a[i].tarp[did]+a[i].tarp[did-1])/2;
            a[i].med=kntd;
        }
        else{
            did=did/2;
            a[i].med=a[i].tarp[did];
        }
    }

    cout<<"Vardas      Pavarde      Galutinis(vid.) / Galutinis(Med.)"<<endl;
    cout<<"------------------------------------------"<<endl;

    for(int i=0; i<m; i++){

        cout<<a[i].vardas<<"      "<<a[i].pavarde<<"      "<<a[i].vid<<"      "<<a[i].med<<endl;
    }





    return 0;
}
