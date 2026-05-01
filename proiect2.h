#ifndef PROIECT2_H_INCLUDED
#define PROIECT2_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>

///PERSOANA///

class Persoana {
protected:
    std::string nume;
public:
    Persoana() {}
    Persoana(const std::string& n) : nume(n) {}
    std::string getNume() const { return nume; }
    virtual void citire (std::istream& in) = 0;
    void afisareNV() const {
        afisare();
    }
    virtual void afisare() const = 0;
    virtual ~Persoana() {}
};

///STUDENT///

class Student : public Persoana {
    std::string domeniu;
public:
    Student() {}
    Student(const std::string& n, const std::string& domeniu_) : Persoana(n), domeniu(domeniu_) {}

    void citire(std::istream& in) override {
        std::cout << "Nume student: ";
        std::getline(in, nume);
        std::cout << "Domeniul: ";
        std::getline(in, domeniu);
    }

    void afisare() const override {
        std::cout << "\nStudent: " << nume << "; Domeniul: " << domeniu;
    }

    std::string getDomeniu() const { return domeniu; }
};

///CURS///

class Curs {
    std::string nume;
    int credite;
public:
    Curs() {}
    Curs(const std::string& n, int c) : nume(n), credite(c) {}

    std::string getNume() const { return nume; }
    int getCredite() const { return credite; }

    void citire(std::istream& in){
        std::cout << "Nume curs: ";
        std::getline(in, nume);

        std::cout << "Credite: ";
        in >> credite;
        in.ignore();
    }
};

///PROFESOR///

class Profesor : public Persoana {
    Curs curs;

public:
    Profesor() {}
    Profesor(const std::string& n, const Curs& c)
        : Persoana(n), curs(c) {}

    std::string getNumeCurs() const { return curs.getNume(); }
    int getCrediteCurs() const { return curs.getCredite(); }

    void citire(std::istream& in) override {
        std::cout << "Nume profesor: ";
        std::getline(in, nume);

        curs.citire(in);
    }

    void afisare () const override {
        std::cout << "\nProfesor:" << nume
                  << " | " << curs.getNume()
                  << " | " << curs.getCredite() << "\n";

    }
};

///SECRETAR///

class Secretar : public Persoana {
    std::string departament;
    int vechime;

public:
    Secretar() : Persoana(""), departament(""), vechime(0) {}

    Secretar(const std::string& nume_, const std::string& dep, int v)
        : Persoana(nume_), departament(dep), vechime(v){}

    std::string getDepartament() const{
        return departament;
    }

    int getVechime() const{
        return vechime;
    }

    void afisare() const {
        std::cout << "\nSecretar: " << nume
                  << " | Departament: " << departament
                  << " | Vechime: " << vechime << " ani\n";
    }

    void citire(std::istream& in) override{
        std::cout << "Nume secretar: ";
        std::getline(in, nume);

        std::cout << "Departament: ";
        std::getline(in, departament);

        std::cout << "Vechime: ";
        in >> vechime;
        in.ignore();
    }
};

///FACULTATE///

class Facultate {
    std::string nume;
    std::string oras;

public:
    std::vector<Student> studenti;
    std::vector<Profesor> profesori;
    std::vector<Secretar> secretari;
    std::vector<Persoana*> persoane;

    void setDate(const std::string& n, const std::string& o) {
        nume = n;
        oras = o;
    }

    void afisare() {
        std::cout << "Facultate: " << nume << "\n";
        std::cout << "Oras: " << oras << "\n\n";

        std::cout << "Studenti:\n";
        for (auto& s : studenti)
            std::cout << "- " << s.getNume() << "; " << s.getDomeniu() <<"\n";

        std::cout << "\nProfesori:\n";
        for (auto& p : profesori) {
            std::cout << "- " << p.getNume()
                      << " | " << p.getNumeCurs()
                      << " | " << p.getCrediteCurs() << "\n";
        }

        std::cout << "\nSecretari:\n";
        for (auto& s : secretari) {
            std::cout << "- " << s.getNume()
                      << " | " << s.getDepartament()
                      << " | " << s.getVechime() << "\n";
        }

    }

    void afiseazaDate() {
        for (auto p : persoane)
            p->afisare();
    }


    int nrStudentiAdaugati() {
        int nr = 0;
        Persoana* p = new Student();
        for (auto p : persoane){
            if(Student* s = dynamic_cast<Student*>(p))
                nr += 1;
        }
        return nr;
    }


};

#endif // PROIECT2_H_INCLUDED
