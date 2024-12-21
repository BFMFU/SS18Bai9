#include<stdio.h>
#include<string.h>
int main(){
	struct Dish{
		int id;
		char dish[50];
		int price;
	};
	struct Dish menu[100]={
		{1,"Raw Tuna",199000},
		{2,"Sweet and sour pork",79000},
		{3,"Rice bowl",5000},
		{4,"Beef Steak",299000},
		{5,"Crap soup",79000},
		{6,"Fish and chip",149000}
	};
	int choice;
	int size=6;
	do{
		printf("\n \t MENU \t\n");
		printf("1. In ra gia tri cac phan tu co trong menu\n");
		printf("2. Them mot phan tu vao vi tri chi dinh\n");
		printf("3. Sua mot phan tu o vi tri chi dinh\n");
		printf("4. Xoa mot phan tu o vi tri chi dinh\n");
		printf("5. Sap xep cac phan tu\n");
		printf("6. Tim kiem phan tu theo name nhap vao \n");
		printf("7. Thoat.\n");
		printf("Lua chon cua ban la: ");
		scanf("%d",&choice);
		switch (choice){
			case 1:{
				for (int i=0;i<size;i++){
					printf("\nId: %d\t Name: %12s\t Price: %d\t",menu[i].id,menu[i].dish,menu[i].price);
				}
				break;
			}
			case 2:{
				int pos=6;
				fflush(stdin);
				printf("Nhap ten mon an: ");
				fgets(menu[pos].dish,50,stdin);
				printf("Nhap gia mon an: ");
				scanf("%d", &menu[pos].price);
				menu[pos].id = pos + 1;
				size++;
				break;
			}
			case 3:{
				int pos;
				printf("Nhap vi tri muon sua : ");
				scanf("%d", &pos);
				if (pos < 0 || pos >= size) {
					printf("Vi tri khong hop le.\n");
					break;
				}
				fflush(stdin);
				printf("Nhap ten mon moi: ");
				fgets(menu[pos].dish,100,stdin);
				printf("Nhap gia mon moi: ");
				scanf("%d", &menu[pos].price);
				break;
			}
			case 4:{
				int pos=0;
				for (int i = pos; i < size - 1; i++) {
					menu[i] = menu[i + 1];
				}
				size--;
				break;
			}
			case 5:{
				for (int i = 1; i < size; i++) {
					struct Dish key = menu[i];
					int j = i - 1;
					while (j >= 0 && menu[j].price < key.price) {
						menu[j + 1] = menu[j];
						j--;
					}
					menu[j + 1] = key;
				}
				printf("Menu sau khi sap xep lai theo gia tien la: \n");
				for (int i = 0; i < size; i++) {
					printf("\nId: %d\t Name: %12s\t Price: %d\t", menu[i].id, menu[i].dish, menu[i].price);
				}
				break;
			}
			case 6:{
				char str[50];
				int found = 0;
				fflush(stdin);
				printf("Nhap ten mon ban can tim: ");
				fgets(str,50,stdin);
				for (int i = 0; i < size; i++) {
					int match = 1;
					for (int j = 0; str[j] != '\0' && menu[i].dish[j] != '\0'; j++) {
						if (str[j] != menu[i].dish[j]) {
							match = 0;
							break;
						}
					}
					if (match) {
						found = 1;
						printf("\nTim thay mon an: Id: %d\t Name: %s\t Price: %d\n", menu[i].id, menu[i].dish, menu[i].price);
					}
				}
				if (!found) {
					printf("Khong tim thay mon an trong menu.\n");
				}
				break;
			}
			case 7:{
				printf("Thoat chuong trinh.\n");
				break;
			}
			default:{
				printf("Lua chon khong hop le. Vui long chon lai.\n");
				break;
			}
		}
	}while(choice != 7);
	return 0;
}


