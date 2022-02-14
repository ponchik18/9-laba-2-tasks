//Сохранить в переменную имя файла 
//сделать отчистку файла 
//


#include"functions.h"


int main() {
	setlocale(0, "rus");
	n = 0;
	service* name=new service[n];
	bool flag = true;
	int num = 0;
	service* d;
	char a;
	
	OpenOrCreatingFile();
	
	while (flag) {
		if (global_falg == 0) {
			system("cls");
			cout << "Введите количесво машин в автосервисе(это будет максимальное количество машин): " << endl;
			cin >> n;
			name = new service[n];
			global_falg = 1;
		}
		else if (global_falg == 2) {
			int c;
			rewind(fp);
			fread(&num, 4, 1, fp);
			cout << "С файла считано " << num << " машин, хотите ли вы добавить ещё несколько" << endl;
			do {
				cout << "Введите 0- если нет, и число большее 0 - если да " << endl;
				cin >> c;
			} while (c<0);
			n = num + c;
			name = new service[n];
			ReadFromFile(name, num);
			global_falg = 1;
			system("cls");
		}
		switch (menu())
		{case read:
			if (num<n) {
				cout<<"Отлично, давайте добавим машину, пока вы заполнили данные для "<<num<< " машин " << endl;
				read_str(name, num);
				num++;
			}
			else {
				cout << "Вы ввели максимальное количество машин" << endl;
			}
			break;
		case sort:
			sort_str(name, num);
			break;
		case research:
			research_str(name, num);
			break;
		case change:
			change_str(name, num);
			break;
		case del:
			delet_str(name, &num);
			break;
		case print:
			print_str(name, num);
			break;
		case print_file:
			if (trigger() == 0) {
				PrintInFile(name, num);
				cout << "Запись завершена" << endl;
			}
			else {
				cout << "В данном файле есть информация, действительно ли вы желаеть переписать данные\n\t1-Да\n\t2-Нет" << endl;
				cin.get();
				cin.get(a);
				switch (a) {
				case '1':
					PrintInFile(name, num);
					cout << "Запись завершена" << endl;
					break;
				case '2':
					continue;
					break;
				default:
					cout<<"Вы выбрали неверное значение"<< endl;
				}
			}

			break;
		case delet:
			fclose(fp);
			fp = fopen(name_file, "w");
			cout << "Отчиста завершена" << endl;
			break;
		case exit_:
			flag = false;
			break;
		default:
			printf("\nНеизвестная операция попробуй ещё раз\n");
			break;
		}
	}
	delete[] name;
	fclose(fp);
	return 0;
}
//////////
