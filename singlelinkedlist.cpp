#include <iostream>
#include <cstddef>  // Untuk NULL

using namespace std;

class Node {
public:
    int noMhs;
    Node* next;
};

class LinkedList {
    Node* START;

public:
    LinkedList() {
        START = NULL;
    }

    void addNode() {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        Node* nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs) {
            if ((START != NULL) && (nim == START->noMhs)) {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node* previous = START;
        Node* current = START;

        while ((current != NULL) && (nim >= current->noMhs)) {
            if (nim == current->noMhs) {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty() {
        return (START == NULL);
    }

    bool Search(int nim, Node*& previous, Node*& current) {
        previous = START;
        current = START;

        while ((current != NULL) && (nim != current->noMhs)) {
            previous = current;
            current = current->next;
        }
        return (current != NULL);
    }

    bool delNode(int nim) {
        Node* current, * previous;
        if (!Search(nim, previous, current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse() {
        if (listEmpty()) {
            cout << "\nList Kosong\n";
        } else {
            cout << "\nData di dalam list adalah:\n";
            Node* currentNode = START;
            while (currentNode != NULL) {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main() {
    LinkedList mhs;
    int nim;
    char ch;

    do {
        cout << "\nMenu";
        cout << "\n1. Menambahkan data ke dalam list";
        cout << "\n2. Menampilkan semua data di list";
        cout << "\n3. Menghapus data berdasarkan nim";
        cout << "\n4. Mencari data dalam list";
        cout << "\n5. Keluar";
        cout << "\nMasukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch) {
            case '1':
                mhs.addNode();
                break;
            case '2':
                if (mhs.listEmpty())
                    cout << "\nList Kosong" << endl;
                else
                    mhs.traverse();
                break;
            case '3':
                cout << "\nMasukkan nim mahasiswa yang akan dihapus : ";
                cin >> nim;
                if (mhs.delNode(nim))
                    cout << "\nData dengan nomor mahasiswa " << nim << " berhasil dihapus" << endl;
                else
                    cout << "\nData tidak ditemukan" << endl;
                break;
            case '4': {
                if (mhs.listEmpty()) {
                    cout << "\nList Kosong\n";
                    break;
                }
                Node* previous, * current;
                cout << "\nMasukkan nim mahasiswa yang dicari : ";
                cin >> nim;
                if (!mhs.Search(nim, previous, current))
                    cout << "\nData tidak ditemukan\n";
                else {
                    cout << "\nData ditemukan\n";
                    cout << "\nNIM Mahasiswa : " << current->noMhs << endl;
                }
                break;
            }
            case '5':
                break;
            default:
                cout << "\nPilihan salah!\n";
                break;
        }
    } while (ch != '5');
}
