#include <iostream>
#include <time.h>
#include <sstream>

using namespace std;

bool czyRokPrzestepny( int rok );
int wpiszRok();
int wpiszMiesiac();
int wpiszDzien();
int wpiszDateNaTypInt();
int obliczLiczbaDniWMiesiacu( int miesiac, int rok );
int pobierzAktualnyRok();
int pobierzAktualnyMiesiac();
int pobierzAktualnyDzien();
int pobierzAktualnaDateTypInt();
int wczytajLiczbeCalkowita();
bool czyPrawidlowyRok(int rok);
bool czyPrawidlowyMiesiac(int miesiac);
bool czyPrawidlowyDzien(int dzien);
string konwerjsaIntNaString(int liczba);
string zamienDateNaString(int rok, int miesiac, int dzien);
string zamienDateNaStringOddzieloneKreskami();
string zamienRokNaString(int rok);
string zamienMiesiacNaString(int miesiac);
string zamienDzienNaString(int dzien);
float zamienPrzecinekNaKropkeWLiczbie (string wyraz);
int pobierzDateDlaPierwszegoDniaAktualnegoMiesiaca();
int pobierzDateDlaPierwszegoDniaPoprzedniegoMiesiaca();
int pobierzDateDlaOstatniegoDniaPoprzedniegoMiesiaca();

// porownanie dwoch dat
bool sprawdzCzyPierwszyArgumentJestMniejszy( int, int );
// lub typu int jesli chce by zwrocono starsza date
int sprawdzKtoraDataJestStarsza( int, int  );


int main() {

    /* mozemy przetestowac Wybrany ROK:
        int rok = wpiszRok();
        int miesiac = wpiszMiesiac();
        int dzien = wpiszDzien();

    */
    int rok = 2011;
    int miesiac = 5;
    int dzien = 31;
    // int wpiszDate();
    int liczbaDni = obliczLiczbaDniWMiesiacu( miesiac, rok );
    cout << "Liczba dni w aktualnym miesiacu: " << liczbaDni << endl;
    cout <<"Aktualna data: " << pobierzAktualnyRok()<< "-" << pobierzAktualnyMiesiac()<< "-" << pobierzAktualnyDzien() << endl;
    cout << "Aktualna data typu Int: " << pobierzAktualnaDateTypInt() << endl;
    string tenRok = zamienRokNaString(pobierzAktualnyRok());
    cout << "Rok na string: " << tenRok << endl;
    string tenMiesiac = zamienMiesiacNaString(pobierzAktualnyMiesiac());
    cout << "Miesiac na string: " << tenMiesiac << endl;
    string tenDzien = zamienDzienNaString(pobierzAktualnyDzien());
    cout << "dzien na string: " << tenDzien << endl;
    cout << "Przecinek , zmieniony na kropke . : " << zamienPrzecinekNaKropkeWLiczbie("15,36") << endl;
    string dataNaString = zamienDateNaString( rok, miesiac, dzien);
    cout << "data Na String: " << dataNaString << endl;
    int dataPierwszegodniaAktualnegoMiesiaca = pobierzDateDlaPierwszegoDniaAktualnegoMiesiaca();
    cout << dataPierwszegodniaAktualnegoMiesiaca << endl;
    string dataString =  zamienDateNaStringOddzieloneKreskami();
    cout << "Cala data na string oddzielona kreskami: " << dataString << endl;
    int poprzedniMiesiac = pobierzDateDlaPierwszegoDniaPoprzedniegoMiesiaca();
    cout << "Data dla pierwszego dnia poprzedniego Miesiac : " << poprzedniMiesiac << endl;
    int ostatniDzienPoprzMiesiaca = pobierzDateDlaOstatniegoDniaPoprzedniegoMiesiaca();
    cout << "Data dla ostatniego dnia poprzedniego Miesiaca: " << ostatniDzienPoprzMiesiaca << endl;
    int toMojaData =  wpiszDateNaTypInt();
    cout << "to Moja Data typu int: " << toMojaData << endl;
    cout << "Starsza jest data 20110101 :" << sprawdzKtoraDataJestStarsza( 20110101, 20001231 ) << endl;
    return 0;
}

bool czyRokPrzestepny( int rok ) {
    return(( rok % 4 == 0 && rok % 100 != 0 ) ||( rok % 400 == 0 ) );
}

int wpiszRok() {

    int rok = 0;
    do {
        cout << "Wpisz rok: ";
        rok = wczytajLiczbeCalkowita();
    } while (czyPrawidlowyRok(rok) == false);

    return rok;
}
int wpiszMiesiac() {

    int miesiac = 0;
    do {
        cout << "Wpisz miesiac: ";
        miesiac = wczytajLiczbeCalkowita();
    } while (czyPrawidlowyMiesiac(miesiac) == false);

    return miesiac;
}

int wpiszDzien() {

    int dzien = 0;
    do {
        cout << "Wpisz dzien: ";
        dzien = wczytajLiczbeCalkowita();
    } while (czyPrawidlowyDzien(dzien) == false);

    return dzien;
}

int wpiszDateNaTypInt() {

    string dataString = "";
    int dataInt = 0;
    dataString = zamienDateNaString( wpiszRok(), wpiszMiesiac(), wpiszDzien() );
    dataInt = atoi(dataString.c_str());

    return dataInt;
}

int obliczLiczbaDniWMiesiacu( int miesiac, int rok ) {

    int iloscDniWMiesiacu = 0;
    if( miesiac == 2 ) {
        if( czyRokPrzestepny( rok ) ) iloscDniWMiesiacu = 29;
        else iloscDniWMiesiacu = 28;
    } else if (( miesiac == 4 ) || ( miesiac == 6 ) || ( miesiac == 9 ) || ( miesiac == 11 ) )
        iloscDniWMiesiacu = 30;
    else iloscDniWMiesiacu = 31;

    return iloscDniWMiesiacu;
}

int pobierzAktualnyRok() {

    time_t czas = time( & czas );
    struct tm * data;
    data = localtime( & czas );
    int aktualnyRok = ( data->tm_year + 1900 );

    return aktualnyRok;
}

int pobierzAktualnyMiesiac() {

    time_t czas = time( & czas );
    struct tm * data;
    data = localtime( & czas );
    int aktualnyMiesiac = ( data->tm_mon + 1 );

    return aktualnyMiesiac;
}

int pobierzAktualnyDzien() {

    time_t czas = time( & czas );
    struct tm * data;
    data = localtime( & czas );
    int aktualnyDzien = data->tm_mday;

    return aktualnyDzien;
}

int pobierzAktualnaDateTypInt() {
    string dataString = "";
    int dataInt = 0;
    dataString = zamienDateNaString( pobierzAktualnyRok(), pobierzAktualnyMiesiac(), pobierzAktualnyDzien() );
    dataInt = atoi(dataString.c_str());

    return dataInt;
}

int wczytajLiczbeCalkowita() {
    string wejscie = "";
    int liczba = 0;

    while (true) {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

bool czyPrawidlowyRok(int rok) {

    time_t czas = time( & czas );
    struct tm * data;
    data = localtime( & czas );
    if ((rok >= 2000) && (rok <= data->tm_year + 1900 )) {
        return rok;
    } else return 0;
}

bool czyPrawidlowyMiesiac(int miesiac) {

    if ((miesiac >= 1) && (miesiac <= 12 )) {
        return miesiac;
    } else return 0;
}


bool czyPrawidlowyDzien(int dzien) {

    if ((dzien >= 1) && (dzien <= 31 )) {
        return dzien;
    } else return 0;
}

string konwerjsaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string zamienRokNaString(int rok) {

    string rokNaString = konwerjsaIntNaString( rok );
    return rokNaString;
}

string zamienMiesiacNaString(int miesiac) {

    string miesiacNaString = konwerjsaIntNaString( miesiac );
    if(miesiacNaString.size() < 2 )  miesiacNaString.insert(0,"0");
    return miesiacNaString;
}

string zamienDzienNaString(int dzien) {

    string dzienNaString = konwerjsaIntNaString( dzien );
    if(dzienNaString.size() < 2 )  dzienNaString.insert(0,"0");

    return dzienNaString;
}

string zamienDateNaString( int rok, int miesiac, int dzien ) {

    string rokNaString = zamienRokNaString( rok );
    string miesiacNaString = zamienMiesiacNaString( miesiac );
    string dzienNaString = zamienDzienNaString( dzien );

    string dataZmienionaNaZapisString = rokNaString + miesiacNaString + dzienNaString;

    return dataZmienionaNaZapisString;
}

string zamienDateNaStringOddzieloneKreskami() {

    string rokNaString = konwerjsaIntNaString(pobierzAktualnyRok());
    string miesiacNaString = konwerjsaIntNaString(pobierzAktualnyMiesiac());
    string dzienNaString = konwerjsaIntNaString(pobierzAktualnyDzien());

    if(miesiacNaString.size() < 2 )  miesiacNaString.insert(0,"0");
    if(dzienNaString.size() < 2 )  dzienNaString.insert(0,"0");
    string dataZmienionaNaStringOddzieloneKreskami = rokNaString + "-" + miesiacNaString + "-" + dzienNaString;

    return dataZmienionaNaStringOddzieloneKreskami;
}

float zamienPrzecinekNaKropkeWLiczbie (string wyraz) {

    for (int i = 0; i < wyraz.size(); i++) {
        if(wyraz[i] == ',') wyraz[i] = '.';
    }
    float liczbaFloatZKropka = stof(wyraz);

    return liczbaFloatZKropka;
}

int pobierzDateDlaPierwszegoDniaAktualnegoMiesiaca() {

    string numerJeden = "01";
    string dataPierwszegoDniaAktualnegoMiesiaca = "";

    int dataDlaPierwszegoDniaAktualnegoMiesiaca = 0;

    dataPierwszegoDniaAktualnegoMiesiaca = zamienRokNaString( pobierzAktualnyRok() ) + zamienMiesiacNaString( pobierzAktualnyMiesiac() ) + numerJeden;
    dataDlaPierwszegoDniaAktualnegoMiesiaca = atoi(dataPierwszegoDniaAktualnegoMiesiaca.c_str());

    return dataDlaPierwszegoDniaAktualnegoMiesiaca;
}

int pobierzDateDlaPierwszegoDniaPoprzedniegoMiesiaca() {

    string numerJeden = "01";
    string dataPierwszegoDniaPoprzedniegoMiesiaca = "";

    int iloscMiesiecy = 12;
    int dataDlaPierwszegoDniaPoprzedniegoMiesiaca = 0;
    int aktualnyMiesiacInt = pobierzAktualnyMiesiac();
    int aktualnyRokInt = pobierzAktualnyRok();

    if ( aktualnyMiesiacInt == 1 ) {
        aktualnyMiesiacInt = iloscMiesiecy;
        aktualnyRokInt = aktualnyRokInt - 1;
    } else {
        aktualnyMiesiacInt--;
    }
    dataPierwszegoDniaPoprzedniegoMiesiaca = zamienRokNaString( aktualnyRokInt ) + zamienMiesiacNaString( aktualnyMiesiacInt ) + numerJeden;
    dataDlaPierwszegoDniaPoprzedniegoMiesiaca = atoi(dataPierwszegoDniaPoprzedniegoMiesiaca.c_str());

    return dataDlaPierwszegoDniaPoprzedniegoMiesiaca;
}

int pobierzDateDlaOstatniegoDniaPoprzedniegoMiesiaca() {

    string dataOstatniegoDniaPoprzedniegoMiesiaca = "";
    int iloscDniWPoprzedniMiesiacu = 0;
    int iloscMiesiecy = 12;
    int dataDlaOstatniegoDniaPoprzedniegoMiesiaca = 0;
    int aktualnyMiesiacInt = pobierzAktualnyMiesiac();
    int aktualnyRokInt = pobierzAktualnyRok();

    if ( aktualnyMiesiacInt == 1 ) {
        aktualnyMiesiacInt = iloscMiesiecy;
        aktualnyRokInt = aktualnyRokInt - 1;
    } else {
        aktualnyMiesiacInt--;
    }
    iloscDniWPoprzedniMiesiacu = obliczLiczbaDniWMiesiacu( aktualnyMiesiacInt, aktualnyRokInt );
    dataOstatniegoDniaPoprzedniegoMiesiaca = zamienRokNaString( aktualnyRokInt ) + zamienMiesiacNaString( aktualnyMiesiacInt ) + zamienDzienNaString( iloscDniWPoprzedniMiesiacu );
    dataDlaOstatniegoDniaPoprzedniegoMiesiaca = atoi(dataOstatniegoDniaPoprzedniegoMiesiaca.c_str());

    return dataDlaOstatniegoDniaPoprzedniegoMiesiaca;
}


bool sprawdzCzyPierwszyArgumentJestMniejszy( int pierwszyArgument, int drugiArgument ) {

    if ( pierwszyArgument < drugiArgument ) {
        return 1;
    } else {
        return 0;
    }
}

int sprawdzKtoraDataJestStarsza( int pierwszyArgument, int drugiArgument ) {

    if ( pierwszyArgument < drugiArgument ) {
        cout << "Pierwsza data jest starsza" << endl;
        return pierwszyArgument;
    } else {
        cout << "Druga data jest starsza" << endl;
        return drugiArgument;
    }
}
