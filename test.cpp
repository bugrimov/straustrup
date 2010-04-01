#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

map<string,bool> was;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}



string find2 (string dir, string filename)
{

  //cout << "START: " << dir << endl;
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) != NULL) {

    while ((dirp = readdir(dp)) != NULL) {
      string dirname = string(dirp->d_name);
      if (dirname == string(".") || dirname == string(".."))
        continue;

      if (dirname == filename && !was[dir + "\\" + dirname])
      {
        was[dir + "\\" + dirname] = true;
        return dir + "\\" + dirname;

      }
      else
      {
        //cout << "goto" << endl;
        string founded = find2(dir + "\\" + dirname, filename);
        if (founded != "")
          return founded;
      }
    }
    closedir(dp);
    return "";
  }
  else
  {
      //cout << "Error(" << errno << ") opening " << dir << endl;
      return "";
  }

}

string findfile(string dir, string filename)
{

    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << files[i] << endl;
    }
    return 0;

  
}

int main_NO()
{
string dir = string(".");

cout << find2(dir, "test.cpp");
cout << find2(dir, "1.txt");

 /*
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << files[i] << endl;
    }
 */
    return 0;
}
