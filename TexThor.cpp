/******************************************
*                                         *
*               Mini Project              *
*       Pemrograman Beroriantasi Objek    *
*                 TexThor                 *
*                                         *
******************************************/

// Nandito Ananda Ginting (221402045)
// Oswald Adrian Silalahi (221402082)
// Samuel Bintang Christoper Silaen (221402131)
// Muhammad Naufal Azmi Lubis (221402073)

#include <iostream> 
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <windows.h>

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define ITALIC "\033[3m"

using namespace std;

class TextEditor
{
private:
    string filename;
    vector<string> hore;

public:
    void run();                         // fungsi untuk menjalankan program                                     [[ Oswald Adrian ]]
    void displayMainMenu();             // fungsi untuk menampilkan opsi menu                                   [[ Oswald Adrian ]]
    void processChoice(int choice);     // fungsi untuk memproses pilihan pengguna                              [[ Oswald Adrian ]]
    void BuatFile();                    // fungsi untuk membuat file baru                                       [[ Samuel Silaen ]]
    void TambahFile();                  // fungsi untuk menambahkan teks kedalam sebuah file                    [[ M. Naufal ]]
    void BacaFile();                    // fungsi untuk membaca & menampilkan isi dari sebuah file              [[ M. Naufal ]]
    void KosongkanFile();               // fungsi untuk mengosongkan isi file                                   [[ Nandito Ananda ]]
    void HapusFile();                   // fungsi untuk menghapus file                                          [[ Nandito Ananda ]]
    void copyFile();                    // fungsi untuk menyalin isi file dari satu file ke file lain           [[ Samuel Silaen ]]
    void editFile();                    // fungsi untuk mengubah isi file                                       [[ Nandito Ananda ]]
    void runCode();                     // fungsi untuk meng-compile & run code program dari sebuah file        [[ OSwald Adrian ]]
    void exitProgram();                 // fungsi untuk mengakhiri program                                      [[ M. Naufal ]]

};

// {{- Fungsi untuk menjalankan program -}}
void TextEditor::run()
{
        int choice = 0;
        system("CLS");
        cout << "Loading ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << BLUE <<"\n\n=====================================================================" << endl;
        cout << BOLD << GREEN << "\t\t\t\tTexThor" << RESET << endl;
        cout << BLUE << "=====================================================================";
        while (choice != 9)
        {
            displayMainMenu();
            cout << "\033[34m"
                 << "Masukkan pilihan : "
                 << "\033[0m";
            cin >> choice;
            processChoice(choice);
        }
}

// {{- Fungsi untuk menampilkan menu -}}
void TextEditor::displayMainMenu()
{
        cout << "\n\n\n";
        cout << BOLD << UNDERLINE << "\t\tMain Menu\n"
             << RESET << endl;
        cout << "1. Buat File" << endl;
        cout << "2. Tambah Text ke File" << endl;
        cout << "3. Read from File" << endl;
        cout << "4. Kosongkan File" << endl;
        cout << "5. Hapus File" << endl;
        cout << "6. Copy File" << endl;
        cout << "7. Edit File" << endl;
        cout << "8. Run Code" << endl;
        cout << RED << ITALIC << "9. Exit" << RESET << endl
             << endl;
}

// {{- Fungsi untuk memproses inputan user -}}
void TextEditor::processChoice(int choice)
{
        switch (choice)
        {
        case 1:                 
            BuatFile();
            break;
        case 2:
            TambahFile();      
            break;
        case 3:
            BacaFile();        
            break;
        case 4:
            KosongkanFile();    
            break;
        case 5:
            HapusFile();       
            break;
        case 6:
            copyFile();  
            break;
        case 7:
            editFile();       
            break;
        case 8:
            runCode();      
            break;
        case 9:
            exitProgram(); 
            break;
        default:
            cout << "Hanya angka 1 Sampai 9." << endl;
        }
}

// {{- Fungsi untuk membuat file baru -}}
void TextEditor::BuatFile()
{
        string filename;
        system("CLS"); 
        cout << "Buat File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << YELLOW << "\t\t\tBuat File \n"
             << RESET;
        cout << endl
             << "Masukkan nama file : ";
        cin.ignore();
        getline(cin, filename);
        ofstream myfile(filename);
        myfile.close();
        system("CLS");
        cout << "Membuat file ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout  << CYAN <<"\n\n\n\t\t\tFile " << MAGENTA << filename << CYAN << " berhasil dibuat!" << RESET << endl; 
        Sleep(3000);
        system("CLS");
}

// {{- Fungsi untuk menambahkan teks kedalam file -}}
void TextEditor::TambahFile()
{
        string filename;
        string teks;
        system("CLS");
        cout << "Tambah Text ke File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << BLUE << "\t\t\tTambah Text ke File \n"
             << RESET;
        cout << endl
             << "Masukkan nama file : "; 
        cin.ignore();
        getline(cin, filename);
        cout << BLUE << "Sedang membuka file : " << RESET << filename << endl;
        string line;
        cout << "\n\nMasukkan teks yang ingin ditambahkan ke file : " << "Akhiri dengan " << RED << "END" << RESET << " jika selesai." << endl;
        getline(cin, teks);
        while (getline(cin, line))
            {
                if (line == "END")
                {
                    break;
                }
                teks += line + "\n";
            }
        ofstream myfile;
        myfile.open(filename, ios_base::app);
        myfile << teks << endl;
        myfile.close();
        system("CLS");
        cout << "Menambahkan teks ke file ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << CYAN << BOLD << "\n\n\n\t\t\tTeks berhasil ditambahkan ke file " << MAGENTA << filename << RESET << CYAN << "!" << RESET << endl;
        Sleep(3000);
        system("CLS");
}

// {{- Fungsi untuk membaca isi file -}}
void TextEditor::BacaFile()
{
        string filename;
        string text;
        system("CLS");
        cout << "Baca File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << YELLOW << "\t\t\tBaca File \n"
             << RESET;
        cout << endl
             << "Masukkan nama file : ";
        cin.ignore();
        getline(cin, filename);
        ifstream myfile(filename);
        cout << BOLD << BLUE << "\nSedang membuka file : " << RESET << filename << " \n\n" <<endl;
        if (myfile)
        {
            while (getline(myfile, text))
            {
                cout << text << endl;
            }
            myfile.close();
        }
        else
        {
            system("CLS");
            cout << RED << "\n\n\n\n\t\t\t\t\tFile not found." << RESET << endl;

            for (int i = 0; i < 5; i++)
            {
                Sleep(3000);
                run();
            }
        }
        cout << endl
             << "Press Enter to continue..." << endl;
        cin.ignore();
        run();
}

// {{- Fungsi untuk menghapus isi file -}}
void TextEditor::KosongkanFile()
{
        string filename;
        system("CLS");
        cout << "Kosongkan File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << MAGENTA << "\t\t\tKosongkan File \n"
             << RESET;
        cout << endl
             << "Masukkan nama file : ";
        cin.ignore();
        getline(cin, filename);
        ofstream myfile;
        myfile.open(filename, ofstream::out | ofstream::trunc);
        myfile.close();
        system("CLS");
        cout << "Mengosongkan file ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << CYAN << BOLD << "\n\n\n\t\t\tFile " << MAGENTA << filename << RESET << CYAN << " berhasil dikosongkan!" << RESET << endl;
        Sleep(3000);
        system("CLS");
}

// {{- Fungsi untuk menghapus file -}}
void TextEditor::HapusFile()
{
        string filename;
        system("CLS");
        cout << "Hapus File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << RED << "\t\t\tHapus File \n"
             << RESET;
        cout << endl
             << "Masukkan nama file : ";
        cin.ignore();
        getline(cin, filename);
        if (remove(filename.c_str()) == 0)
        {
            system("CLS");
            cout << CYAN << "\n\n\n\t\t\tFile " << MAGENTA << filename << CYAN << " berhasil dihapus!" << RESET << endl;
        }
        else
        {
            system("CLS");
            cout << RED  << "\n\n\n\t\t\tFile tidak ditemukan." << RESET <<endl;
        }
        Sleep(3000);
        system("CLS");
}

// {{- Fungsi untuk menyalin isi file -}}
void TextEditor::copyFile()
{
        string sourceFile, destFile;
        system("CLS");
        cout << "Copy File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << GREEN << "\t\t\tCopy File \n"
             << RESET;
        cout << endl
             << "Masukkan nama file sumber : ";
        cin.ignore();
        getline(cin, sourceFile);
        cout << "Masukkan nama file tujuan : ";
        getline(cin, destFile);
        ifstream src(sourceFile, ios::binary);
        ofstream dst(destFile, ios::binary);
        dst << src.rdbuf();
        src.close();
        dst.close();
        system("CLS");
        cout << "Mengcopy file ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << CYAN << "\n\n\n\t\t\tFile "<< RESET << MAGENTA << sourceFile << CYAN <<" berhasil di-copy ke " << MAGENTA << destFile << CYAN << "!" << RESET <<endl;
        Sleep(3000);
        system("CLS");
}

//{{- Fungsi untuk merubah isi file -}}
void TextEditor::editFile()
{
            system("CLS");
        cout << "Edit File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(500);
            cout << ". ";
        }
        string line;
        // Membaca nama file
        string namaFile;
         system("CLS");
        cout << BOLD << UNDERLINE << YELLOW << "\t\t\tEdit File\n"
             << RESET << endl;
        cout << "Masukkan nama file: ";
        cin.ignore();
        getline(cin, namaFile);

        ifstream file(namaFile);
        if (!file)
        {
            cout << "Gagal membuka file." << endl;
            return;
        }
        cout << BOLD << BLUE << "Sedang membuka file : " << RESET << namaFile <<endl;
        string isiFile;
        char karakter;
        while (file.get(karakter))
        {
            isiFile += karakter;
        }
        file.close();
        cout << "\n\n";
        cout << isiFile << endl;

        string teksLama;
        cout << "\n\nMasukkan teks yang ingin diedit || Tekan \33[31mEND\33[0m untuk Selesai : " << endl;
        getline(cin, teksLama);
          while (getline(cin, line))
            {
                if (line == "END")
                {
                    break;
                }
                teksLama += line + "\n";
            }
        string teksBaru;
        cout << "Masukkan teks baru || Tekan \33[31mEND\33[0m untuk Selesai : " << endl;
        getline(cin, teksBaru);
          while (getline(cin, line))
            {
                if (line == "END")
                {
                    break;
                }
                teksBaru += line + "\n";
            }
        size_t pos = isiFile.find(teksLama);
        while (pos != string::npos)
        {
            isiFile.replace(pos, teksLama.length(), teksBaru);
            pos = isiFile.find(teksLama, pos + teksBaru.length());
        }

        ofstream outputFile(namaFile);
        if (!outputFile)
        {
            cout << "Gagal menyimpan perubahan ke file." << endl;
            return;
        }
        system("CLS");
            cout << BOLD << CYAN << "\n\t\t\t\tTeks berhasil di edit.\n\n\n"
                 << RESET;
        
        outputFile << isiFile;
        outputFile.close();
        cout << BLUE << "Isi file setelah di Edit :" << RESET <<endl;
        cout << isiFile << endl;
        // Membuat baris baru
        cout << endl;
        cout << endl
             << "Press Enter to continue..." << endl;
        cin.ignore();
        run();
}

// {{- Fungsi untuk compile & run program pada isi file -}}
void TextEditor::runCode()
{
        system("CLS");
        cout << "Run Code ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << BLUE << "\t\t\tRun Code \n"
             << RESET;
        cout << endl
             << "Masukkan nama file yang ingin dijalankan : ";
        string filename;
        cin.ignore();
        getline(cin, filename);
        cout <<"\n\n";
        system(("g++ -o " + filename.substr(0, filename.find_last_of('.')) + " " + filename).c_str());
        system((".\\" + filename.substr(0, filename.find_last_of('.'))).c_str());
        cout<<"\n\n";
        system("pause");
        system("CLS");
}

// {{- Fungsi untuk mengakhiri program -}}
void TextEditor::exitProgram()
{
        system("CLS");
        cout << "Exiting ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << RED << "\t\t\tKeluar" << RESET << endl;
        Sleep(3000);
        exit(0);
        system("CLS");
}

// {{- Fungsi Utama -}}
int main()
{
    TextEditor editor;
    editor.run();           // memanggil fungsi run untuk memulai program
    return 0;
}
