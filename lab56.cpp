#include <iostream>
using namespace std;

class zoo{
  private:
    char* name;
    int len_name;
    char* country;
    int len_country;
    char** list;
    int *len_animals;
    char* time_working;
    int price;
    int count;
  public:
    zoo(){
        len_name = 11;
        name = new char[len_name];
        len_country = 7;
        country = new char[len_country];
        list = new char* [count];
        time_working = new char[14];
        char tt[14] = "00:00 - 00:00";
        for(int i = 0; i < 14; i++){
            time_working[i] = tt[i];
        }
        char cc[7] = "Russia";
        for(int i = 0; i < len_country; i++){
            country[i] = cc[i];
        }
        char nn[11] = "Closed zoo";
        for(int i = 0; i < len_name; i++){
            name[i] = nn[i];
        }
        price = count = 0;
        len_animals = new int[count];
        for(int i = 0; i < count; i++){
            list[i] = new char;
            len_animals[i] = 0;
        }
    }
    zoo(char name[], int name_len, char country[], int country_len, char time[], int count, int price, char list[], int len_list){
        this->len_name = name_len;
        this->len_country = country_len;
        this->count = count;
        this->price = price;
        this->name = new char[name_len];
        this->country = new char[country_len];
        this->list = new char* [count];
        this->time_working = new char[14];
        for(int i = 0; i < 14; i++){
            time_working[i] = time[i];
        }
        for(int i = 0; i < country_len; i++){
            this->country[i] = country[i];
        }
        for(int i = 0; i < name_len; i++){
            this->name[i] = name[i];
        }
        this->len_animals = new int[count];
        for(int i = 0; i < count; i++){
            this->list[i] = new char;
            this->len_animals[i] = 0;
        }
        int ii = 0;
        char c;
        for(int i = 0; i < len_list; i++){
            c = list[i];
            if(c != ' '){
                this->list[ii][len_animals[ii]] = c;
                this->len_animals[ii]++;
            }
            else{
                ii++;
            }
        }
    }
    zoo(const zoo &other){
        this->count = other.count;
        this->len_country = other.len_country;
        this->len_name = other.len_name;
        this->price = other.price;
        this->len_animals = new int[this->count];
        for(int i = 0; i < this->count; i++){
            this->len_animals[i] = other.len_animals[i];
        }
        this->name = new char[this->len_name];
        for(int i = 0; i < this->len_name; i++){
            this->name[i] = other.name[i];
        }
        this->country = new char[this->len_country];
        for(int i = 0; i < this->len_country; i++){
            this->country[i] = other.country[i];
        }
        this->list = new char*[this->count];
        for(int i = 0; i < count; i++){
            this->list[i] = new char[this->len_animals[i]];
        }
        this->time_working = new char;
        for(int i = 0; i < 13; i++){
            this->time_working[i] = other.time_working[i];
        }
    }
    ~zoo(){
        delete[] name;
        delete[] country;
        for(int i = 0; i < count; i++){
            delete[] list[i];
        }
        delete[] list;
        delete[] len_animals;
        delete[] time_working;
    }
    void update_price(){
        cout << "Введите новую цену" << endl;
        cin >> price;
        getchar();
    }
    int get_price(){
        return price;
    }
    double get_pn(){
        if(count == 0){
            return 0;
        }
        else{
            return ((double) price / count);
        }
    }
    void show_price(){
        cout << "Цена за билет: " << price << " рублей" << endl; 
    }
    void update_count(){
        cout << "Введите количество животных" << endl;
        int c;
        cin >> c;
        if(c > count){
            for(int i = count; i < c; i++){
                list[i] = new char;
            }
        }
        else if(c < count){
            for(int i = c; i < count; i++){
                delete[] list[i];
            }
        }
        count = c;
        getchar();
    }
    int get_count(){
        return count;
    }
    void show_count(){
        if(count % 10 == 1 && count % 100 != 11){
            cout << "В зоопарке " << count << " животное" << endl;
        }
        else if (count <= 0){
            cout << "В зоопарке нет животных" << endl;
        }
        else{
            cout << "В зоопарке " << count << " животных" << endl;
        }
    }
    void update_time(){
        char c;
        bool fl = true;
        int ch1, m1, ch2, m2;
        delete[] time_working;
        time_working = new char[14];
        while(fl){
            cout << "Введите время работы в формате \"12:12 - 21:21\"" << endl;
            for(int i = 0; i < 14; i++){
                c = getchar();
                time_working[i] = c;
            }
            if (time_working[5] != ' ' && time_working[6] != '-' && time_working[7] != ' '){
                cout << "Время введенно неправильно" << endl;
            }
            else if(time_working[0] < '0' || time_working[0] > '2'){
                cout << "Время введенно неправильно" << endl;
            }
            else if(time_working[1] < '0' || time_working[1] > '9'){
                cout << "Время введенно неправильно" << endl;
            }
            else if (time_working[2] != ':'){
                cout << "Время введенно неправильно" << endl;
            }
            else if(time_working[3] < '0' || time_working[3] > '6'){
                cout << "Время введенно неправильно" << endl;
            }
            else if(time_working[4] < '0' || time_working[4] > '9'){
                cout << "Время введенно неправильно" << endl;
            }
            else if(time_working[8] < '0' || time_working[8] > '2'){
                cout << "Время введенно неправильно" << endl;
            }
            else if(time_working[9] < '0' || time_working[9] > '9'){
                cout << "Время введенно неправильно" << endl;
            }
            else if (time_working[10] != ':'){
                cout << "Время введенно неправильно" << endl;
            }
            else if(time_working[11] < '0' || time_working[11] > '6'){
                cout << "Время введенно неправильно" << endl;
            }
            else if(time_working[12] < '0' || time_working[12] > '9'){
                cout << "Время введенно неправильно" << endl;
            }
            else{
                ch1 = int(time_working[0] - '0') * 10 + int(time_working[1] - '0');
                m1 = int(time_working[3] - '0') * 10 + int(time_working[4] - '0');
                ch2 = int(time_working[8] - '0') * 10 + int(time_working[9] - '0');
                m2 = int(time_working[11] - '0') * 10 + int(time_working[12] - '0');
                if(ch1 > 24 || ch2 > 24 || m1 > 59 || m2 > 59){
                    cout << "Время введенно неправильно" << endl;
                }
                else if(ch1 > ch2 || (ch1 == ch2 && m1 > m2)){
                    cout << "Время введенно неправильно" << endl;
                }
                else if(ch2 == 24 && m2 != 0){
                    cout << "Время введенно неправильно" << endl;
                }
                else{
                    break;
                }
            }
        }
    }
    void show_time(){
        cout << "Время работы зоопарка: ";
        for(int i = 0; i < 13; i++){
            cout << time_working[i];
        }
        cout << endl;
    }
    char* get_time_working(){
        return time_working;
    }
    void update_name(){
        cout << "Введите название зоопарка в одну строчку" << endl;
        char c;
        c = getchar();
        delete[] name;
        name = new char;
        len_name = 0;
        while(c != '\n'){
            name[len_name] = c;
            len_name++;
            c = getchar();
        }
    }
    void show_name(){
        cout << "Зоопарк называется: ";
        for(int i = 0; i < len_name; i++){
            cout << name[i];
        }
        cout << endl;
    }
    void name_name(){
        for(int i = 0; i < len_name; i++){
            cout << name[i];
        }
        cout << endl;
    }
    char* get_name(){
        return name;
    }
    void update_country(){
        cout << "Введите название страны, в которой расположен зоопарк, в одну строчку" << endl;
        char c;
        c = getchar();
        delete[] country;
        country = new char;
        len_country = 0;
        while(c != '\n'){
            country[len_country] = c;
            len_country++;
            c = getchar();
        }
    }
    void show_country(){
        cout << "Страна зоопарка: ";
        for(int i = 0; i < len_country; i++){
            cout << country[i];
        }
        cout << endl;
    }
    char* get_country(){
        return country;
    }
    int get_len_country(){
        return len_country;
    }
    void update_list(){
        cout << "Введите список всех животных по порядку, каждое в отдельной строчке" << endl;
        for(int i = 0; i < count; i++){
            delete[] list[i];
        }
        delete[] list;
        delete[] len_animals;
        list = new char*[count];
        len_animals = new int[count];
        for(int i = 0; i < count; i++){
            list[i] = new char;
            len_animals[i] = 0;
        }
        for(int i = 0; i < count; i++){
            char c;
            c = getchar();
            while(c != '\n'){
                list[i][len_animals[i]] = c;
                len_animals[i]++;
                c = getchar();
            }
        }
    }
    void show_list(){
        if (count != 0){
            cout << "Список животных зоопарка:" << endl;
            for(int i = 0; i < count; i++){
                for(int j = 0; j < len_animals[i]; j++){
                    cout << list[i][j];
                }
                cout << endl;
            }
        }
        else{
            cout << "В зоопарке нет животных" << endl;
        }
    }
    void show_information(){
        show_name();
        show_country();
        show_time();
        show_price();
        show_count();
        show_list();
    }
    void update_infotmation(){
        update_name();
        update_country();
        update_time();
        update_price();
        update_count();
        update_list();
    }
};

int how_much(zoo z, int n){
    int x;
    int start_time, end_time, all_time;
    start_time = (int(z.get_time_working()[0] - '0') * 10 + int(z.get_time_working()[1] - '0')) * 60;
    start_time += (int(z.get_time_working()[3] - '0') * 10 + int(z.get_time_working()[4] - '0'));
    end_time = (int(z.get_time_working()[8] - '0') * 10 + int(z.get_time_working()[9] - '0')) * 60;
    end_time += (int(z.get_time_working()[11] - '0') * 10 + int(z.get_time_working()[12] - '0'));
    all_time = end_time - start_time;
    if(z.get_count() * n <= all_time){
        x = z.get_count();
    }
    else{
        x = all_time / n;
    }
    return x;
}
void in_country(zoo sp[], int sp_len, char country[], int country_len){
    for(int i = 0; i < sp_len; i++){
        if(sp[i].get_len_country() != country_len){
        }
        else{
            bool fl = true;
            for(int j = 0; j < country_len; j++){
                if(sp[i].get_country()[j] != country[j]){
                    fl = false;
                    break;
                }
            }
            if(fl){
                sp[i].name_name();
            }
        }
    }
}
void pn_sort(zoo sp[], int sp_len){
    bool pn_fl_sp[sp_len];
    double MAXIMUM = 0;
    for(int i = 0; i < sp_len; i++){
        pn_fl_sp[i] = false;
        if(sp[i].get_pn() > MAXIMUM){
            MAXIMUM = sp[i].get_pn();
        }
    }
    double maxx;
    for(int i = 0; i < sp_len; i++){
        maxx = MAXIMUM;
        for(int i = 0; i < sp_len; i++){
            if(sp[i].get_pn() <= maxx && !pn_fl_sp[i]){
                maxx = sp[i].get_pn();
            }
        }
        for(int i = 0; i < sp_len; i++){
            if(sp[i].get_pn() == maxx && !pn_fl_sp[i]){
                pn_fl_sp[i] = true;
                sp[i].name_name();
            }
        }
    }
}

int main(){
    zoo z3("big", 3, "Niderland", 9, "12:30 - 13:00", 3, 150, "dog cat parrot", 14);
    zoo z2("small", 5, "Niderland", 9, "11:00 - 17:00", 2, 20, "kitty doggy", 11);
    zoo z1("best", 4, "Russia", 6, "00:00 - 24:00", 5, 1000, "rhino camel elephant tiger lion", 31);
    z1.show_information();
    zoo spi[3] = {z1, z3, z2};
    pn_sort(spi, 3);
    zoo z4;
    z4.update_infotmation();
    z4.show_information();
    z4.update_count();
    z4.show_count();
    z4.update_list();
    z4.show_list();
    cout << how_much(z4, 10) << endl;
    zoo spisok[4] = {z1, z2, z3, z4};
    in_country(spisok, 4, "Niderland", 9);
    return 0;
}