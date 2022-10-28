#include "DBfile.h"
#include "screen.h"

using namespace std;

static const char* books[] = {"name","author","time_published"};
static const char* books_ints[] = { "pages" };
static const char* characters[] = {"name","primary/secondary"};

int main() {
	dbfile DBBooks = dbfile("Books","Books", 1, books_ints, 3, books);
	dbfile DBCharacters = dbfile("Characters","Characters", 0, NULL, 2, characters);
//	dbfile DBSessions = dbfile("Sessions", "Sessions", 2, sessions, 0, NULL);
	//pointers to previous dbfile variables
//    DBSessions.InsertSlaveDBFile(&DBPlayers);
//	DBSessions.InsertSlaveDBFile(&DBServers);
//	DBPlayers.SetMasterDBFile(&DBSessions,0);
//	DBServers.SetMasterDBFile(&DBSessions,1);

	string stateM;
	do {
		cls();
		cout << "    Select Database table:\n"
		     << "(0) Exit menu\n"
		     << "(1) Books table\n"
		     << "(2) Characters table\n"
//		     << "(3) Sessions table\n"
		     << "Type a number from 0 to 3 to continue: ";
		cin >> stateM;
		cls();

		if (stateM == "1") {
			DBBooks.DBApp();
		}
		else if (stateM == "2") {
//			DBServers.PrintFromAnotherTable(DBPlayers);
//			pause();
			DBCharacters.DBApp();
		}
//		else if (stateM == "3") {
//			DBSessions.DBApp();
//		}
		else if (stateM != "0") {
			cout << "************************\n"
				<< "ERROR: incorrect option. Should be a number from 0 to 3\n"
				<< "************************\n";
		}
		//pause();

	} while (stateM != "0");
}
