#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;
class proprietar{
private:
    string nume;
public:
    proprietar(){}
    string getname(){
    return nume;
    }
    friend istream& operator >>(istream &in, proprietar x)
    {
        in>>x.nume;
        return in;
    }
    friend class farmacie;
};
class farmacie{
protected:
    proprietar x;
    string nume;
public:
    farmacie(string nume):nume(nume){

    }
    virtual ~farmacie(){}
    //farmacie(){}
    string getnume(){
    return nume;
    }
    virtual void citire(istream&)=0;
    friend istream& operator >>(istream &in,farmacie *a)
    {
        //in>>a->x;
        a->citire(in);
        return in;
    }
    virtual void afisare()=0;
    virtual string getweb()=0;
    virtual int getviz()=0;
    virtual int getdiscount()=0;
};
class farmacie_offline:public farmacie{
private:
    int nr_angj;
    int profit;
public:
    farmacie_offline():farmacie(nume){}
    farmacie_offline(string nm,int nr, int pro):farmacie(nume){
    //cout<<"vibe check"<<endl;
    //cout<<nume<<" "<<nr<<" "<<pro<<endl;
    this->nume=nm;
    this->nr_angj=nr;
    this->profit=pro;
    //cout<<this->nume<<" "<<this->nr_angj<<" "<<this->profit<<endl;
    }
    ~farmacie_offline(){}
    void citire(istream& in){
    //cout<<"lmao"<<endl;
    in>>nume>>nr_angj>>profit;
    cout<<nume<<" "<<nr_angj<<" "<<profit<<endl;
    }
    string getweb(){}
    int getviz(){}
    int getdiscount(){}
    void afisare(){
    cout<<nume<<endl<<nr_angj<<" "<<profit<<endl;
    }
};
class farmacie_online:public farmacie{
private:
    string web;
    int nr_viz;
    int discount;
public:
    farmacie_online():farmacie(nume){
    }
    farmacie_online(string nm,string adr,int nr,int disc):farmacie(nume){
    this->nume=nm;
    this->web=adr;
    this->nr_viz=nr;
    this->discount=disc;
    }
    virtual ~farmacie_online(){}
    void citire(istream& in){
    //in>>nume;
    in>>nume>>web>>nr_viz>>discount;
    }
    string getweb(){
    return web;
    }
    int getviz(){
    return nr_viz;
    }
    int getdiscount(){
    return discount;
    }
    void afisare(){
    cout<<nume<<endl<<web<<endl<<nr_viz<<" "<<discount<<endl;
    }
    farmacie_online* operator =(farmacie_online* ob)
    {
        this->nume=ob->nume;
        this->web=ob->web;
        this->nr_viz=ob->nr_viz;
        this->discount=ob->discount;
        return this;
    }
};
class structura_date{
private:
    static structura_date *str;
    vector<tuple<string,string,int,int>> t;
    structura_date(){}
public:
    static structura_date* getst(){
    if(str==0)
    {
        str=new structura_date();
    }
    return str;
    }
    void add(auto tt)
    {
    t.push_back(tt);
    }
    void afis()
    {
    for(auto &i:t)
    {
        cout<<get<0>(i)<<endl<<get<1>(i)<<" "<<get<2>(i)<<" "<<get<3>(i)<<endl;
    }
    }
    auto entry(string s)
    {
    for(auto &i:t)
    {
        if(get<0>(i)==s)return make_tuple(get<0>(i),get<1>(i),get<2>(i),get<3>(i));
    }
    }
};
//class structura_date;
template<typename x>
class Gestionare_Farmacii{
private:
    x *lant[101];
    const int idlant=1;
    int index;
    const int maxindex=101;
public:
    Gestionare_Farmacii(){
    //lant=NULL;
    index=0;
    }
    void add(string s){
    structura_date *st=structura_date::getst();
    index++;
    auto t=st->entry(s);
    //if(lant==NULL)*lant=new farmacie[101];
    lant[index]=new farmacie_online(get<0>(t),get<1>(t),get<2>(t),get<3>(t));
    }
    //tuple<string,string,int,int>
    //Gestionare_Farmacii<farmacie>* operator +=(string);
    /*Gestionare_Farmacii<farmacie>* operator +(string s){
    structura_date *st=structura_date::getst();
    this->add(st->entry(s));
    return this;
    }*/
    /*Gestionare_Farmacii<farmacie>* operator +=(string s){
    structura_date *st=structura_date::getst();
    add(st->entry(s));
    return this;
    }*/
    Gestionare_Farmacii<farmacie>* operator =(Gestionare_Farmacii<farmacie>* ob){
        this->idlant=ob->idlant;
        this->index=ob->index;
        this->lant=ob->lant;
        this->maxindex=ob->maxindex;
        return this;
    }
    void afis(){
    cout<<lant[index]->getnume()<<" "<<lant[index]->getweb()<<" "<<lant[index]->getviz()<<" "<<lant[index]->getdiscount()<<endl;
    }
    //Gestionare_Farmacii<farmacie>* operator +=
    friend class structura_date;
};
structura_date* structura_date::str = 0;

int main(){
structura_date *s=structura_date::getst();
//structura_date* structura_date::str = ;
/*farmacie *a=new farmacie_offline();
cin>>a;
a->afisare();
cout<<"numar obiecte:"<<endl;
delete a;*/

/*for(int i=1;i<=n;i++){
    b=new farmacie_online();
    cin>>b;
    string web=b->getweb();
    int nr=b->getviz();
    int disc=b->getdiscount();
    cout<<"am pregatit datele"<<endl;
    v.push_back(make_tuple(web,nr,disc));
    cout<<"am inregistrat datele"<<endl;
    delete b;
}*/

string web;
int nr,disc;
/*for(int i=1;i<=n;i++)
{
    b=new farmacie_online();
    cin>>b;
    //std::tuple<string,int,int> tt=make_tuple("sugi",10,1);
    s->add(make_tuple(b->getweb(),b->getviz(),b->getdiscount()));
    delete b;
}*/
//s->afis();
farmacie *b;
Gestionare_Farmacii<farmacie>* g=new Gestionare_Farmacii<farmacie>;
//farmacie *lmao=new farmacie[101];
int n;
//cin>>n;
//for(int i=1;i<=n;i++)
//{
    b=new farmacie_online();
    cin>>b;
    s->add(make_tuple(b->getnume(),b->getweb(),b->getviz(),b->getdiscount()));
    auto t=s->entry(b->getnume());
    string lmao=b->getnume();
    //g+=lmao;
    g->add(lmao);
    delete b;
    g->afis();
//}
/*cin>>b;
b->afisare();
delete b;*/
//error: no match for 'operator+=' (operand types are 'structura_date*' and 'std::tuple<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, int, int>')|
//vector<tuple<web,nr_viz,discount>>
}
