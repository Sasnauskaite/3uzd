#include <string>
#include "Zmogus.h"
using std::string;

class Studentas : public Zmogus {
	protected:
		double avg;
		double med;
		int skolaAvg;
		int skolaMed;
	public:
		Studentas() {};
		Studentas(string name_, string lastname_, double avg_, double med_, int skolaAvg_, int skolaMed_){
			name = name_;
			lastname = lastname_;
			avg = avg_;
			med = med_;
			skolaAvg = skolaAvg_;
			skolaMed = skolaMed_;
		};


		inline const double get_avg(){
			return avg;
		}

		inline const double get_med(){
			return med;
		}

		inline const int get_skolaAvg(){
			return skolaAvg;
		}

		inline const int get_skolaMed(){
			return skolaMed;
		}

		void set_name(string name_){
			name = name_;
		}
		
		void set_lastname(string lastname_){
			lastname = lastname_;
		}

		void set_avg(double avg_){
			avg = avg_;
		}

		void set_med(double med_){
			med = med_;
		}

		void set_skolaAvg(int skolaAvg_){
			skolaAvg = skolaAvg_;
		}

		void set_skolaMed(int skolaMed_){
			skolaMed = skolaMed_;
		}

        string inicialai() { return (!name.empty() && !lastname.empty())?name[0]+"."+lastname[0]:"Undefined";}

		Studentas(const Studentas &a) { //kopijavimo konstruktorius
			name = a.name;
			lastname = a.lastname;
			avg = a.avg;
			med = a.med;
			skolaAvg = a.skolaAvg;
			skolaMed = a.skolaMed;
		 }

		Studentas&  operator=(const Studentas& a){ //priskyrimo operatorius
			if (&a == this) return *this;
			name = a.name;
			lastname = a.lastname;
			avg = a.avg;
			med = a.med;
			skolaAvg = a.skolaAvg;
			skolaMed = a.skolaMed;
			return *this;
		}
		~Studentas(){ //destruktorius

		}
};
class Galvocius :  public Studentas{
	
};
class Vargselis :  public Studentas{
	
};