#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Product
{
private:
    int id;
    string name;
    float price;
    int stock;
    string category;

public:
    Product(int id, string name, float price, int stock, string category)
    {
        this->id = id;
        this->name = name;
        this->price = price;
        this->stock = stock;
        this->category = category;
    }

    void updatePrice(float newPrice)
    {
        if (newPrice > 0)
        {
            price = newPrice;
        }
        else
        {
            cout << "Harga tidak valid!" << endl;
        }
    }

    void updateStock(int jumlah)
    {
        if (stock + jumlah >= 0)
        {
            stock += jumlah;
        }
        else
        {
            cout << "Stok tidak mencukupi!" << endl;
        }
    }

    float getDiscountedPrice()
    {
        float discount = 0;
        if (category == "Elektronik")
            discount = 0.1;
        if (category == "Pakaian")
            discount = 0.15;
        if (category == "Makanan")
            discount = 0.05;
        return price - (price * discount);
    }

    string formatRupiah(float angka)
    {
        ostringstream oss;
        oss << fixed << setprecision(0) << angka; // Ubah angka jadi string tanpa desimal
        string numStr = oss.str();
        string formatted = "";

        int count = 0;
        for (int i = numStr.length() - 1; i >= 0; i--)
        {
            formatted = numStr[i] + formatted;
            count++;
            if (count % 3 == 0 && i != 0)
            {
                formatted = "." + formatted;
            }
        }
        return formatted;
    }

    void displayInfo()
    {
        cout << "ID Produk: " << id << endl;
        cout << "Nama: " << name << endl;
        cout << "Harga: Rp " << formatRupiah(price)
             << " (Setelah Diskon: Rp " << formatRupiah(getDiscountedPrice()) << ")" << endl;
        cout << "Stok: " << stock << " pcs" << endl;
        cout << "Kategori: " << category << endl;
        cout << "----------------------" << endl;
    }
};

int main()
{
    Product laptop(001, "Laptop Gaming", 15000000, 5, "Elektronik");
    Product baju(002, "Kaos Polos", 100000, 20, "Pakaian");
    Product snack(003, "Keripik Kentang", 20000, 50, "Makanan");

    laptop.displayInfo();
    baju.displayInfo();
    snack.displayInfo();

    cout << "Mengupdate harga dan stok..." << endl;
    laptop.updatePrice(14000000);
    baju.updateStock(-5);

    laptop.displayInfo();
    baju.displayInfo();

    return 0;
}
