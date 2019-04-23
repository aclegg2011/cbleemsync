//
// Created by screemer on 2018-12-15.
//

#ifndef CBLEEMSYNC_SCANNER_H
#define CBLEEMSYNC_SCANNER_H

#include "../main.h"
#include "game.h"
#include "database.h"
#include "../gui/gui.h"

using namespace std;

class Scanner {
public:
    Scanner() {}
    vector<Game*> games;

    void scanDirectory(string path);
    void repairBrokenCueFiles(string path);
    bool isFirstRun(string path, Database * db);
    void unecm(const string & path); // this routine removes Error Correction files from the bin file to save space
    void updateDB(Database *db);
    bool forceScan=false;
    bool noGamesFound=false;
    void detectAndSortGamefiles(string path);
    Scanner(Scanner const &) = delete;
    Scanner &operator=(Scanner const &) = delete;
    static std::shared_ptr<Scanner> getInstance() {
        static std::shared_ptr<Scanner> s{new Scanner};
        return s;
    }

private:

    int getImageType(string path);
    bool complete;
    void moveFolderIfNeeded(DirEntry entry, string gameDataPath, string path);
};


#endif //CBLEEMSYNC_SCANNER_H
