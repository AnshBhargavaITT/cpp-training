#include<iostream>

class Geeks
{
    int private_var;
    protected:
    int protected_var;
    public:
    Geeks()
    {
        private_var=10;
        protected_var=20;
    }
    friend class GFG;
};
class GFG
{
    public:
    void display(Geeks& g)
    {
        std::cout<<g.private_var<<std::endl;
        std::cout<<g.protected_var<<std::endl;
    }
};
int main()
{
    GFG gfg;
    Geeks geeks;
    gfg.display(geeks);
    return 0;
}