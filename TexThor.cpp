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

/* {{- Header File -}}*/
#include <iostream> 
#include <fstream>  
#include <string>
#include <cstdlib>
#include <vector>
#include <windows.h>

/* {{- Pendefinisain konstanta warna untuk tampilan -}}*/
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
#define Bg_White "\u001b[47m"

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

/* {{- Fungsi untuk menjalankan program -}}
    Fungsi dibuat oleh: Oswald Adrian S -> 24-05-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */
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
cout << BLUE <<"\n\n\t\t\t\t=====================================================================" << RESET << endl;
        cout << BOLD GREEN<< "\t\t\t\t\t\t\t\t  TexThor" << RESET << endl;
        cout << ITALIC BLACK Bg_White << "\t\t\t\t\t\t\t\tVersion " <<"0.9" << RESET << endl;
        cout << BLUE << "\t\t\t\t=====================================================================";
        while (choice != 9)
        {
            displayMainMenu();              // Program menampilkan menu pilihan kepada user & meminta user untuk menginputkan angka yang ingin dipilih.
            cout << "\033[34m"
                 << "Masukkan pilihan : "
                 << "\033[0m";
            cin >> choice;
            processChoice(choice);          // Inputan user akan diproses fungsi processChoice() sesuai dengan inputan yang dipilih user.
        }
}

/* {{- Fungsi untuk menampilkan menu -}}
    Fungsi dibuar oleh: Oswald Adrian S -> 24-05-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */
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

/* {{- Fungsi untuk memproses inputan user -}}
    Fungsi dibuat oleh: Oswald Adrian S -> 24-05-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */
void TextEditor::processChoice(int choice)
{
        switch (choice)
        {
        case 1:                     // Apabila user memilih 1 maka akan memanggil fungsi BuatFile().
            BuatFile();             
            break;
        case 2:                     // Apabila user memilih 2 maka akan memanggil fungsi TambahFile().
            TambahFile();
            break;
        case 3:                     // Apabila user memilih 3 maka akan memanggil fungsi BacaFile().
            BacaFile();
            break;
        case 4:                     // Apabila user memilih 4 maka akan memanggil fungsi KosongkanFile().
            KosongkanFile();
            break;
        case 5:                     // Apabila user memilih 5 maka akan memanggil fungsi HapusFile().
            HapusFile();
            break;  
        case 6:                     // Apabila user memilih 6 maka akan memanggil fungsi copyFile().
            copyFile();
            break;
        case 7:                     // Apabila user memilih 07 maka akan memanggil fungsi editFile().
            editFile();
            break;
        case 8:                     // Apabila user memilih 8 maka akan memanggil fungsi runCode().
            runCode();
            break;  
        case 9:                     // Apabila user memilih 9 maka akan memanggil fungsi exitProgram().
            exitProgram();
            break;
        default:
            cout << "Hanya angka 1 Sampai 9." << endl;
        }
}

/* {{- Fungsi untuk membuat file baru -}}
    Fungsi dibuat oleh Samuel Silaen -> 26-05-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */
void TextEditor::BuatFile()
{
        string filename;
        system("CLS");
        cout << "Buat File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);                 // Styling tampilan terminal.
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << YELLOW << "\t\t\tBuat File \n"
             << RESET;
        cout << endl
             << "Masukkan nama file : ";    
        cin.ignore(); // Mengabaikan baris baru.
        getline(cin, filename);
        ofstream myfile(filename);          // Membuat file menggunakan objek ofstream sesuai dengan inputan user.
        myfile.close();
        system("CLS");
        cout << "Membuat file ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);                 // Styling tampilan terminal.
            cout << ". ";
        }
        system("CLS");
        cout  << CYAN <<"\n\n\n\t\t\tFile " << MAGENTA << filename << CYAN << " berhasil dibuat!" << RESET << endl;
        Sleep(3000);
        system("CLS");
}

/* {{- Fungsi untuk menambahkan teks kedalam file -}}
    Fungsi dibuat oleh: M. Naufal -> 27-05-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */
void TextEditor::TambahFile()
{
        string filename;        // Menyimpan nama file.
        string teks;            // Menyimpan teks dalam file.
        system("CLS");
        cout << "Tambah Text ke File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);                 // Styling tampilan pada terminal.
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << BLUE << "\t\t\tTambah Text ke File \n"
             << RESET;
        cout << endl
             << "Masukkan nama file : ";
        cin.ignore();     // Mengabaikan baris baru.
        getline(cin, filename);         // Mencari nama file melalui string filename.
        cout << BLUE << "Sedang membuka file : " << RESET << filename << endl;
        string line;            // Menyimpan line dalam file.
        cout << "\n\nMasukkan teks yang ingin ditambahkan ke file : " << "Tekan " << RED << "END" << RESET << " jika selesai." << endl;
        getline(cin, teks);
        while (getline(cin, line))
            {
                if (line == "END")      // Menyelesaikan inputan teks yang ingin ditambah pada file apabila user menuliskan "END".
                {
                    break;
                }
                teks += line + "\n";
            }
        ofstream myfile;                // Menuliskan teks kedalam file.       
        myfile.open(filename, ios_base::app);
        myfile << teks << endl;
        myfile.close();
        system("CLS");
        cout << "Menambahkan teks ke file ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);             // Styling tampilan pada terminal.
            cout << ". ";
        }
        system("CLS");
        cout << CYAN << BOLD << "\n\n\n\t\t\tTeks berhasil ditambahkan ke file " << MAGENTA << filename << RESET << CYAN << "!" << RESET << endl;
        Sleep(3000);
        system("CLS");
}

/* {{- Fungsi untuk membaca isi file -}} 
    Fungsi dibuat oleh: M. Naufal -> 29-05-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */
void TextEditor::BacaFile()
{
        string filename;        // Menyimpan nama file.
        string text;            // Menyimpan isi teks dalam file.
        system("CLS");
        cout << "Baca File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);                 // Styling tampilan pada terminal.
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << BLUE << "\t\t\tTambah Text ke File \n" << RESET;
        cout << "Masukkan nama file : ";
        cin.ignore();       // Mengabaikan baris baru.
        getline(cin, filename);
        ifstream myfile(filename);          // Membuka file seusai inputan user melalui string filename.
        cout << BLUE <<"Sedang membuka file: " << RESET << filename << endl << endl;        // Menampilkan isi teks dalam file
        if (myfile)
        {
            int characterCount = 0;
            while (getline(myfile, text))
            {
                cout << text << endl;
                characterCount += text.length();        // Menghitung jumlah karakter dalam file.
            }
            myfile.close();
            cout << GREEN <<"Jumlah karakter dalam file : " << RESET << characterCount << endl;     
        }
        else        // Pengkondisian apabila nama file yang diinputkan user tidak dapat ditemukan.
        {
            system("CLS");
            cout << RED <<"\n\n\n\n\t\t\t\t\tFile not found." << RESET << endl;

            for (int i = 0; i < 5; i++)
            {
                Sleep(3000);
                run();
            }
        }
        cout << endl << "Press Enter to continue..." << endl;
        cin.ignore();   // Mengabaikan baris baru.
        run();
}

/* {{- Fungsi untuk menghapus isi file -}} 
    Fungsi dibuat oleh Nandito Ananda -> 28-05-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */
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
        cout << endl << "Masukkan nama file : ";
        cin.ignore();   // Mengabaikan baris baru.
        getline(cin, filename);
        ofstream myfile;        // Mengosongkan file inputan user.
        myfile.open(filename, ofstream::out | ofstream::trunc);
        myfile.close();
        system("CLS");
        cout << "Mengosongkan file ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);                 // Styling tampilan pada terminal.
            cout << ". ";
        }
        system("CLS");
        cout << CYAN << BOLD << "\n\n\n\t\t\tFile " << MAGENTA << filename << RESET << CYAN << " berhasil dikosongkan!" << RESET << endl;
        Sleep(3000);
        system("CLS");
}

/* {{- Fungsi untuk menghapus file -}} 
    Fungsi dibuat oleh: Nandito Ananda -> 29-05-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */
void TextEditor::HapusFile()
{
        string filename;
        system("CLS");
        cout << "Hapus File ";
        for (int i = 0; i < 5; i++)
        {   
            Sleep(300);             // Styling tampilan pada terminal.
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << RED << "\t\t\tHapus File \n"
             << RESET;
        cout << endl
             << "Masukkan nama file : ";
        cin.ignore();   // Mengabaikan baris baru.
        getline(cin, filename);      // Mengambil nama file yang ingin dihapus user.
        if (remove(filename.c_str()) == 0)  // Pengkondisian penghapusan file.
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

/* {{- Fungsi untuk menyalin isi file -}} 
    Fungsi dibuat oleh: Samuel Silaen -> 01-06-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */ 
void TextEditor::copyFile()
{
            string sourceFile, destFile;
        system("CLS");
        cout << "Copy File ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);             // Styling tampilan pada terminal.
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << GREEN << "\t\t\tCopy File \n"
             << RESET;
        cout << endl
             << "Masukkan nama file sumber : ";
        cin.ignore();       // Mengabaikan baris baru.
        getline(cin, sourceFile);               // Mengambil nama file sumber yang diinputkan user.
        cout << "Masukkan nama file tujuan : ";
        getline(cin, destFile);                 // Mengambil nama file tujuan yang diinput user.
        ifstream src(sourceFile, ios::binary);  
        ofstream dst(destFile, ios::binary);
        dst << src.rdbuf();
        src.close();
        dst.close();
        system("CLS");
        cout << "Mengcopy file ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);                 // Styling tampilan pada terminal
            cout << ". ";
        }
        system("CLS");
        cout << CYAN << "\n\n\n\t\t\tFile "<< RESET << MAGENTA << sourceFile << CYAN <<" berhasil di-copy ke " << MAGENTA << destFile << CYAN << "!" << RESET <<endl;
        Sleep(3000);
        system("CLS");
}

/* {{- Fungsi untuk merubah isi file -}} 
    Fungsi dibuat oleh: Nandito Ananda -> 03-06-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */
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
        cin.ignore();       // Mengabaikan baris baru.
        getline(cin, namaFile);
        ifstream file(namaFile);            // Membuka file
        if (!file)                          // Pengkondisian membuka file
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
                if (line == "END")              // Membaca apabila user menuliskan "END" maka kalimat yang ingin  di edit akan dimulai
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
                if (line == "END")             // Membaca apabila user menuliskan "END" maka fungsi edit akan selesai
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

        ofstream outputFile(namaFile);          // Menyimpan teks yang sudah diedit ke file
        if (!outputFile)                        // Pengkondisian menyimpan edit file
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
        cin.ignore();           // Mengabaikan baris baru
        run();
}

/* {{- Fungsi untuk compile & run program pada isi file -}}
    Fungsi dibuat oleh: Oswald Adrian S -> 31-05-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */ 
void TextEditor::runCode()
{
        system("CLS");
        cout << "Run Code ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);                 // Styling tampilan pada terminal.
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << UNDERLINE << BLUE << "\t\t\tRun Code \n"
             << RESET;
        cout << endl
             << "Masukkan nama file yang ingin dijalankan : ";
        string filename;        // Membuka file
        cin.ignore();   // Mengabaikan baris baru.
        getline(cin, filename);
        cout <<"\n\n";
        system(("g++ -o " + filename.substr(0, filename.find_last_of('.')) + " " + filename).c_str());      // Perintah system untuk mengkompilasi kode program dalam file
        system((".\\" + filename.substr(0, filename.find_last_of('.'))).c_str());                           // Perintah system untuk mengeksekusi kode program yang sudah dikompilasi
        cout<<"\n\n";
        system("pause");
        system("CLS");
}

/* {{- Fungsi untuk mengakhiri program -}} 
    Fungsi dibuat oleh: M. Naufal -> 04-06-2023 
    Dihias oleh: Nandito Ananda -> 05-06-2023 */
void TextEditor::exitProgram()
{
        system("CLS");
        cout << "Exiting ";
        for (int i = 0; i < 5; i++)
        {
            Sleep(300);                 // Styling tampilan pada terminal.
            cout << ". ";
        }
        system("CLS");
        cout << BOLD << RED << "\t\t\tKeluar" << RESET << endl;
        Sleep(3000);
        exit(0);
        system("CLS");
}

/* {{- Fungsi Utama -}} */
int main()
{
    TextEditor editor;
    editor.run();
    return 0;
}
