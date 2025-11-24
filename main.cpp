#include<iostream>
using namespace std;
// +, -, *, /, ==, <, >
class Frac {
    int n;
    int d;
public:
    int N () const { return this->n; }
    int D () const { return this->d; }
    void setN(int x) { this->n = x; }
    void setD(int x) { this->d = x; }

    Frac(const int n, const int d=1) {
        this->n = n;
        this->d = d;
    }
    // Copy C-tor
    Frac (const Frac& orig) {
        this->n = orig.n;
        this->d = orig.d;
    }
    Frac& operator=(const Frac& orig) {
        if (this!=&orig) { // No Self-assignment
            this->n = orig.n;
            this->d = orig.d;
        }
        return *this;
    }
    int NZS(Frac& b) const {
        int nzs=this->D();
        if (this->D()>b.D()) {
            int i=nzs;
            while (nzs%b.D()!=0) {
                nzs+=i;
            }
        }
        else if (this->D()<b.D()) {
            nzs=b.D();
            int i=nzs;
            while (nzs%this->D()!=0) {
                nzs+=i;
            }
        }
        return nzs;
    }
    void print() {
        cout<<this->n <<"/" << this->d;
    }
    Frac operator*(const Frac& b) const {
        Frac c(*this);
        c.setN(this->N() * b.N());
        c.setD(this->D() * b.D());
        return c;
    }
    Frac operator/(const Frac& b) const {
        Frac c(*this);
        c.setN(this->N() * b.D());
        c.setD(this->D() * b.N());
        return c;
    }
    Frac operator+(Frac& b) const {
        Frac c(*this);
        int nzs=this->NZS(b);
        c.setD(nzs);
        c.setN(this->N()*(nzs/this->D())+b.N()*(nzs/b.D()));
        return c;
    }
    Frac operator-(Frac& b) const {
        Frac c(*this);
        int nzs=this->NZS(b);
        c.setD(nzs);
        c.setN(this->N()*(nzs/this->D())-b.N()*(nzs/b.D()));
        return c;
    }
    bool operator==(Frac&b) const {
        int nzs=this->NZS(b);
        if (this->N()*(nzs/this->D())==b.N()*(nzs/b.D())) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator>(Frac&b) const {
        int nzs=this->NZS(b);
        if (this->N()*(nzs/this->D())>b.N()*(nzs/b.D())) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator<(Frac&b) const {
        int nzs=this->NZS(b);
        if (this->N()*(nzs/this->D())<b.N()*(nzs/b.D())) {
            return true;
        }
        else {
            return false;
        }
    }
    ~Frac() {}
};
ostream& operator<<(ostream& o, const Frac& f) {
    o<<f.N() <<"/" << f.D();
    return o;
}
int main() {
    Frac a(2,3);
    Frac b(4,5);
    Frac c(1);
    cout<<a*b<<endl;
    cout<<a/b<<endl;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<(a==b)<<endl;
    cout<<(a>b)<<endl;
    cout<<(a<b)<<endl;
}