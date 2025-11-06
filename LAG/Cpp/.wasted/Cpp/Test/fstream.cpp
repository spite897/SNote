#include<fstream>
#include"Test.cpp"

using std::fstream;

std::string global_var;
void _logTheFile(){
    fstream file;
    file.open("Test_file",std::ios::in);
    getline(file,global_var);
    file.close();
    
}

int main(){
    fstream file;
    Alert(fstream :create new obj);
    file.open("Test_file",std::ios::app);
    Alert(obj.open(fileName , mode) :open files );
    Alert(mode:     std::ios::in    std::ios::out);
    Alert(          std::ios::app   std::ios::ate);
    Alert(          std::ios::trunc               );
    Alert(ate: move cursor to end   trunc: clear file);
    Paging;

    if(!file){
        std::cerr << "Open Failed" <<endl;
        return 1;
    }

    file << "new String";
    Alert(<< \t: type comments);
    file.close();

    file.open("Test_file",std::ios::in);
    std::string read;
    getline(file,read);
    AlertE(read);
    Alert(getline(file,rec) \t: read the file);

    file.close();
    Alert(file.close());
    return 0 ;
}