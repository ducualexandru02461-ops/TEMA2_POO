#ifndef PROIECT2_H_INCLUDED
#define PROIECT2_H_INCLUDED
#include <iostream>
#include <vector>

class Persoana{
protected:
    std::string nume;
    std::string prenume;
public:
    Persoana(const std::string& nume_) : nume(nume_) {}
    ~Persoana(){}
};

class Student : public Persoana{
    int anDeStudiu;
    int grupa;
    char* specializare;
public:
    //Student (){
    //    std::cin >> this->nume;
    //}
    Student () : Persoana("") {
        std::cout << "-Nume: ";
        std::cin >> nume;
    }
    std::string getNume() const{
        return nume;
    }
    ~Student(){}
};

class Curs{
protected:
    std::string nume;
    int credite;
public:
    //Curs(const std::string& nume_){ nume = nume_; }
    //std::string getNume() const{
    //   return numeCurs;
    //}
    void citire() {
        std::cout << "-Nume curs: ";
        std::cin >> nume;

        std::cout << "-Credite: ";
        std::cin >> credite;
    }
    std::string getNume() const {
        return nume;
    }
    int getCredite() const {
        return credite;
    }
    ~Curs(){}
};

class Profesor : public Persoana{;
    Curs curs;
public:
    Profesor () : Persoana("") {
        std::cout << "-Nume profesor: ";
        std::cin >> nume;
    }
    std::string getNume() const{
        return nume;
    }
    std::string getNumeCurs() const{
        return curs.getNume();
    }
    int getCrediteCurs() const{
        return curs.getCredite();
    }
    void setCurs(const Curs& c){
        curs = c;
    }
    ~Profesor(){}
};

class Facultate{
    std::string nume;
    std::string oras;
    std::vector<Student> listaStudenti;
    std::vector<Profesor> listaProfesori;
    std::vector<Curs> listaCursuri;
public:
    void setNume() {std::cin >> nume;}
    void setOras() {std::cin >> oras;}
    void citire(std::string nume){
        std::cout << "-- Please insert name:";
        std::cin >> nume;
    }
    std::string getNume() const { return nume; }
    std::string getOras() const { return oras; }
    ~Facultate(){}
};

#endif // PROIECT2_H_INCLUDED
