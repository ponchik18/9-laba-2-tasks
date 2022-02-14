#include"Header.h"
char name_file[20];
struct master_name {
	char last_name[15];
	char first_name[15];
};
typedef struct car_service {
	char num[7];
	char marka[12];
	int run;
	struct master_name empoyee;
	int sum;
}service;
int global_falg = 0;
FILE* fp = NULL;
int n;
enum menu {
	read = 1, sort, research, change, del, print, print_file, delet,exit_
};
void PrintInFile(service* d, int num);
int menu() {
	int a;
	cout << "Выберите операцию:" << endl;
	cout << "\t1-Ввод данных" << endl;
	cout << "\t2-Сортировка" << endl;
	cout << "\t3-Поиск данных по характеристикам" << endl;
	cout << "\t4-Изменения данных" << endl;
	cout << "\t5-Удаление структуры из массива" << endl;
	cout << "\t6-Ввывод даннных" << endl;
	cout << "\t7-Запись данных в файл" << endl;
	cout << "\t8-Отчистка содержимого файла" << endl;
	cout << "\t9-Выход" << endl;
	cin >> a;
	return a;
}
void read_str(service* d, int i) {

	cout << i + 1 << " авто" << endl;
	fflush(stdin);
	cout << "\tВведите регистрационный знак авто" << endl << "\t";
	cin >> (d + i)->num; /// выбивает исключение
	cout << "\tВведите марку авто" << endl << "\t";
	cin >> (d + i)->marka;
	cout << "\tВведите пробег авто" << endl << "\t";
	cin >> (d + i)->run;
	cout << "\tВведите фамилию мастера, который выполнил ремонт, а затем его имя " << endl << "\t";
	cin >> (d + i)->empoyee.last_name;
	cout << "\t";
	cin >> (d + i)->empoyee.first_name;
	cout << "\tВведите сумму ремонта" << endl << "\t";
	cin >> (d + i)->sum;
	cout << endl;
	return;
}
void print_str(service* d, int n) {
	if (n == 0) {
		cout << "Сначало надо ввести данные" << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " авто" << endl;
		cout << "\tРегистрациооный знак: " << d->num << endl;
		cout << "\tМарка: " << d->marka << endl;
		cout << "\tПробег: " << d->run << endl;
		cout << "\tФамилия и имя мастера: " << d->empoyee.last_name << " " << d->empoyee.first_name << endl;
		cout << "\tСумма ремонта: " << d->sum << endl;
		cout << "____________________________________________________________" << endl;
		d++;
	}
}

void sort_str(service* d, int n) {
	if (n == 0) {
		cout << "Сначало надо ввести данные" << endl;
		return;
	}
	service tmp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp((d + i)->num, (d + j)->num) > 0) {
				tmp = d[i];
				d[i] = d[j];
				d[j] = tmp;

			}
		}
	}
	cout << "Сортировка завершена" << endl;

}

void print_car(service* d, int n);
template<typename T>
void research_str_function(T str, T str2, int& flag, int i, service* d) {
	if (strcmp(str, str2) == 0) {
	cout << "Параметр найден, это " << i + 1 << " автомобиль" << endl;
	print_car(d, i);
	flag++;

	}

}
template <>void research_str_function<int>(int a, int b, int& flag, int i, service* d) {
	if (a == b) {
		cout << "Параметр найден, это " << i + 1 << " автомобиль" << endl;
		print_car(d, i);
		flag++;
	}
}
void research_str(service* d, int n) {
	if (n == 0) {
		cout << "Сначало надо ввести данные" << endl;
		return;
	}
	int a;
	while (1) {
		cout << "Выберите параметр, по которрому будет осущесвлелён поиск:" << endl;
		cout << "\t1-Регистрационный номер" << endl;
		cout << "\t2-Марка автомобиля" << endl;
		cout << "\t3-Пробег автомобиля" << endl;
		cout << "\t4-Фамилия мастера, выполнивший ремонт" << endl;
		cout << "\t5-Имя мастера, выполнивший ремонт" << endl;
		cout << "\t6-Сумма ремонта" << endl;
		cout << "\t7-Выход" << endl;
		cin >> a;
		char str[12];
		int znach;
		int flag = 0;
		switch (a)
		{
		case 1:
			cout << "Введите регистрационный знак" << endl;
			getchar();
			flag = 0;
			gets_s(str);

			for (int i = 0; i < n; i++) {
				research_str_function((d + i)->num, str, flag, i, d);
			}
			if (flag == 0)
				cout << "Автомобиля с такими параметрами не найдено..." << endl;
			break;
		case 2:
			cout << "Введите марку автомобиля" << endl;
			getchar();
			gets_s(str);
			flag = 0;
			cin.clear();
			for (int i = 0; i < n; i++) {
				research_str_function((d + i)->marka, str, flag, i, d);
			}
			if (flag == 0)
				cout << "Автомобиля с такими параметрами не найдено..." << endl;
			break;
		case 3:
			cout << "Введите пробег автомобиля" << endl;
			getchar();
			cin >> znach;
			flag = 0;
			for (int i = 0; i < n; i++)
			{
				research_str_function((d + i)->run, znach, flag, i, d);

			}
			if (flag == 0)
				cout << "Автомобиля с такими параметрами не найдено..." << endl;
			break;
		case 4:
			cout << "Введите фамилию мастера, выполнивший ремонт" << endl;
			getchar();
			gets_s(str);
			flag = 0;
			for (int i = 0; i < n; i++) {
				research_str_function((d + i)->empoyee.last_name, str, flag, i, d);
			}
			if (flag == 0)
				cout << "Автомобиля с такими параметрами не найдено..." << endl;
			break;
		case 5:
			cout << "Введите имя мастера, выполнивший ремонт" << endl;
			getchar();
			gets_s(str);
			flag = 0;
			for (int i = 0; i < n; i++) {
				research_str_function((d + i)->empoyee.first_name, str, flag, i, d);
			}
			if (flag == 0)
				cout << "Автомобиля с такими параметрами не найдено..." << endl;
			break;
		case 6:
			cout << "Введите сумму ремонта" << endl;
			getchar();
			cin >> znach;
			flag = 0;
			for (int i = 0; i < n; i++) {
				research_str_function((d + i)->sum, znach, flag, i, d);
			}
			if (flag == 0)
				cout << "Автомобиля с такими параметрами не найдено..." << endl;
			break;
		case 7:
			cout << "Поиск окончен" << endl;
			return;
			break;
		default:
			cout << "Неверное действие" << endl;
			break;
		}
	}

}


void print_car(service* d, int n) {
	cout << "\tРегистрациооный знак: " << (d + n)->num << endl;
	cout << "\tМарка: " << (d + n)->marka << endl;
	cout << "\tПробег: " << (d + n)->run << endl;
	cout << "\tФамилия и имя мастера: " << (d + n)->empoyee.last_name << " " << (d + n)->empoyee.first_name << endl;
	cout << "\tСумма ремонта: " << (d + n)->sum << endl;
	cout << "______________________________________________________________" << endl;
	return;
}

void change_str(service* d, int n) {
	if (n == 0) {
		cout << "Сначало надо ввести данные" << endl;
		return;
	}
	int a, i;
	while (1) {
		cout << "Выберите параметр, который хотите изменить :" << endl;
		cout << "\t1-Регистрационный номер" << endl;
		cout << "\t2-Марка автомобиля" << endl;
		cout << "\t3-Пробег автомобиля" << endl;
		cout << "\t4-Фамилия мастера, выполнивший ремонт" << endl;
		cout << "\t5-Имя мастера, выполнивший ремонт" << endl;
		cout << "\t6-Сумма ремонта" << endl;
		cout << "\t7-Выход" << endl;
		cin >> a;
		if (a == 7) {
			cout << "Операция завершена" << endl;
			return;
		}
		cout << "Введите порядковый номер авто, который хотите изменить" << endl;
		do {
			cin >> i;
		} while (i > n + 1 && i <= 0);
		i--;
		char str[12];
		int znach;
		switch (a)
		{
		case 1:
			cout << "Введите регистрационный знак" << endl;
			getchar();
			gets_s(str);
			strcpy((d + i)->num, str);
			break;
		case 2:
			cout << "Введите марку автомобиля" << endl;
			getchar();
			gets_s(str);
			strcpy((d + i)->marka, str);
			break;
		case 3:
			cout << "Введите пробег автомобиля" << endl;
			getchar();
			cin >> znach;
			(d + i)->run = znach;
			break;
		case 4:
			cout << "Введите фамилию мастера, выполнивший ремонт" << endl;
			getchar();
			gets_s(str);
			strcpy((d + i)->empoyee.last_name, str);
			break;
		case 5:
			cout << "Введите имя мастера, выполнивший ремонт" << endl;
			getchar();
			gets_s(str);
			strcpy((d + i)->empoyee.first_name, str);
			break;
		case 6:
			cout << "Введите сумму ремонта" << endl;
			getchar();
			cin >> znach;
			break;
		default:
			cout << "Неверная операция" << endl;
			break;
		}

	}
}
void delet_str(service* d, int* num) {
	int a;
	cout << "Выберите параметр удаления" << endl;
	cout << "\t1-Удалить полностью базу" << endl;
	cout << "\t2-Удалить только данные только 1 машины" << endl;
	cin >> a;
	switch (a) {
	case 1:
		delete[] d;
		global_falg = 0;
		*num = 0;
		do {
			cout << "Желаете \n\t1-продолжить работу \n\t2-завершить работу программы" << endl;
			cin >> a;
			if (a != 2 && a != 1) {
				cout << "Неверный знак" << endl;
			}
		} while (a != 1 && a != 2);
		if (a == 2) {
			fclose(fp);
			exit(0);
		}
		break;
	case 2:
		if (*num == 1) {
			global_falg = 0;
		}
		cout << "Введите порядковый номер авто, который хотите удалить" << endl;
		do {
			cin >> a;
		} while (a > *num + 1 && a <= 0);
		a--;
		for (int i = a; i <= *num; i++) {
			d[i] = d[i + 1];
		}
		*num -= 1;
		cout << *num << endl;
		cout << "Операция завершена" << endl;
		break;
	default:
		cout << "Необходимо было выбрать параметр из списка" << endl;
		break;

	}
}

void file_name() {

	cout << "Введите название файла, без расширения"  << endl;
	cin.getline(name_file, 20);
	strcat(name_file, ".txt");
	return;
}
int trigger() {
	rewind(fp);
	int c, flag=0;
	if ((c = getc(fp) != EOF)) {
		flag++;
	}
	if (flag == 0) {
		rewind(fp);
		return 0;
	}
	rewind(fp);
	return 1;
}
void OpenOrCreatingFile() {
		char str[20];
		file_name();
		strcpy(str, name_file);
		if (!(fp = fopen(str, "rb+"))) {
			cout << "Данный файл не найден. Если желаете создать, то нажмите 1" << endl;

			char c;
			cin.get(c).get();
			if (c == '1') {
				if ((fp = fopen(str, "wb+"))) {
					global_falg = 0;
				}
			}
			else {
				cout << "Невозможно открыть файл" << endl;
				exit(0);
			}
		}
		else {			
			if (!trigger()) {
				cout << "Данный файл пуст, невозможно считать с информацию, поэтому вводите данные с клавиатуры" << endl;
				system("pause");

				global_falg = 0;
			}

			else
				global_falg = 2;
		}
	
}
void PrintInFile(service *d, int num){
	rewind(fp);
	fwrite(&num, 4, 1, fp);
	int c;
	int i = 0;
	while (i < num) {
		c = (size_t)strlen((d + i)->num)+1;
		fwrite(&c, sizeof(int), 1, fp);
		fwrite((d+i)->num, sizeof(char), c, fp);
		c = (size_t)strlen((d + i)->marka)+1;
		fwrite(&c, sizeof(int), 1, fp);
		fwrite((d + i)->marka, sizeof(char),c, fp);
		fwrite(&((d + i)->run), sizeof(int), 1, fp);
		c = (size_t)strlen((d + i)->empoyee.last_name)+1;
		fwrite(&c, sizeof(int), 1, fp);
		fwrite((d + i)->empoyee.last_name, sizeof(char),c, fp);
		c = (size_t)strlen((d + i)->empoyee.first_name)+1;
		fwrite(&c, sizeof(int), 1, fp);
		fwrite((d + i)->empoyee.first_name, sizeof(char), c, fp);
		fwrite(&((d + i)->sum), sizeof(int), 1, fp);
		i++;

	}
	return;
}
void ReadFromFile(service* d, int num ) {
	int c;
	int i=0;
	while (i < num) {
		fread(&c, sizeof(int), 1, fp);
		fread((d + i)->num, sizeof(char), c, fp);
		fread(&c, sizeof(int), 1, fp);
		fread((d + i)->marka, sizeof(char), c, fp);
		fread(&((d + i)->run), sizeof(int), 1, fp);
		fread(&c, sizeof(int), 1, fp);
		fread((d + i)->empoyee.last_name, sizeof(char), c, fp);
		fread(&c, sizeof(int), 1, fp);
		fread((d + i)->empoyee.first_name, sizeof(char), c, fp);
		fread(&((d + i)->sum), sizeof(int), 1, fp);
		i++;
	}
	return;
}
/////////////////