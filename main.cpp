#include "File.hpp"
#include <filesystem>
namespace fs = filesystem;
using namespace std;


int main() {
    File file;
    file.userFile();
    cout << endl;
    file.messageFile();
   

    //ofstream("test.txt"); // create file

    //cout << "Created file with permissions: ";
    //demo_perms(fs::status("test.txt").permissions());

    //fs::permissions("test.txt",
    //   fs::perms::others_all,
    //    fs::perm_options::remove);

    //cout << "After removing g-w and o-r:  ";
    //demo_perms(fs::status("test.txt").permissions());

    //fs::remove("test.txt");
    //return 0;
}