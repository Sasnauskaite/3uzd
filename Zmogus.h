#include <string>
using std::string;



class Zmogus {
    protected:
        string name;
		string lastname;

    public:
        virtual string inicialai() = 0;
        inline string get_name() const { return name; }
        inline string get_lastname() const { return lastname; }
};