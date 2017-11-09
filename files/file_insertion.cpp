/* Implementation that sees whether the contents of
   a file that "alredy exists" is opened in "out" mode
   is truncated.

   Observations:

   1. Even if 'trunc' flag is not specified the file's contents
      ARE TRUNCATED i.e., 'trunc' flag is set by defualt.

      To prevent truncation use the following,

          std::ios_base::out | ~std::ios_base::truc

   2. 'ate' positions the file pointer to the of file

       Note: If '~trunc' is not specified along with 'out' then the
       file's contents may be truncated and 'ate' might not be of
       much of use.
*/

#include <fstream>
#include <iostream>

int main() {
     std::fstream f("test.txt", std::ios_base::out | std::ios_base::ate | ~std::ios_base::trunc);
//     std::fstream f("test.txt", std::ios_base::out | ~std::ios_base::trunc);

     f << " added to end.";
     f.seekp(0, std::ios::beg);
     f << "Original";
     f.seekp(0, std::ios::end);
     f << " Final.";

     return 0;
}
