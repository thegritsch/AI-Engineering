// TestApp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <MyString.h>
#include <iostream>

using namespace MystringLib;

int main()
{
    //Teil 1
    String myString("Hello");
    myString.concatenate("World");
    myString.concatenate(myString);
    String otherString(myString);
    String yetAnotherString("AnotherWorld");
    otherString = yetAnotherString;
    std::cout << otherString.c_str();

    // Teil 2
    String s1("Hello");
    const String s2("World");
    s1 += s2;
    String s3 = s1 + s2;
    s3 += "Hello";
    const String s4 = s3 + "World";
    puts(s4);

    //Teil 3
    const String test("Hello World");
    for (String::Iterator it = test.begin(); it != test.end(); ++it) { std::cout << *it << '\n'; }
    std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << '\n';
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
