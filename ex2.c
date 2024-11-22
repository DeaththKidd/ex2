/******************
Name:
ID: 
Assignment: ex2
*******************/

#include <stdio.h>

int main() {

	int choice, faceSize, num, numLength, temp, check,
	 sumRight, sumLeft, sumDeviders, digit,
	  cheer, smile, checker = 0;
	char eyes, nose, mouth;

	do{
		choice = 0;
		printf("Choose an  option:\n");
		printf("\t1. Happy Face\n");
		printf("\t2. Balanced Number\n");
		printf("\t3. Generous Number\n");
		printf("\t4. Circle Of Joy\n");
		printf("\t5. Happy Numbers\n");
		printf("\t6. Festival Of Laughter\n");
		printf("\t7. Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:	
				choice = 0;
				scanf("%*[^\n]%*c");
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf("\n%c %c %c",&eyes,&nose,&mouth);
				printf("Enter face size:\n");
				scanf("\n%d",&faceSize);

				while (faceSize<0 || !(faceSize&1))
				{
					scanf("%*[^\n]%*c");
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("\n%d",&faceSize);
				}
			
    			printf("%c",eyes);
				for(int i=0; i < faceSize; i++)
				{
					printf(" ");
				}
				printf("%c\n",eyes);
				for(int i=0; i < faceSize/2+1; i++)
				{
					printf(" ");
				}
				printf("%c\n",nose);
			
				printf("\\");
				for(int i=0; i < faceSize; i++)
				{
					printf("%c",mouth);;
				}
				printf("/\n");
				break;
			case 2:
				scanf("%*[^\n]%*c");
				choice = 0;
				printf("Enter a number:\n");
				scanf("\n%d", &num);

				while(num<1){
					scanf("%*[^\n]%*c");
					printf("Only positive number is allowed, please try again:\n");
					scanf("\n%d",&num);
				}
				
				temp = num;
				numLength=0;
				
				sumLeft = 0;
				sumRight = 0;

				while(temp>0)
				{
					temp=temp/10;
					numLength++;
				}
				
				temp = num;
				
				check = numLength;
				numLength /= 2;

				for(int i=0; i< numLength;i++){
					sumRight+=temp%10;
					temp /= 10;
				}

				if(check&1){
					temp /= 10;
				}

				for(int i=0; i< numLength;i++){
						sumLeft+=temp%10;
						temp /= 10;
					}
				
				if(sumLeft == sumRight){
					printf("This number is balanced and brings harmony!\n");
				} else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;

			case 3:
				choice=0;
				printf("Enter a number:\n");
				scanf("%d", &num);
				while(num<1){
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}

				sumDeviders = 0;
				temp = num/2;
				for(int i=1; i<=temp;i++){
					if(!(num%i)){
						sumDeviders += i;
					}
				}
				if(sumDeviders > num)
				{
					printf("This number is generous!\n");
				} else{
					printf("This number does not share.\n");
				}
				break;

			case 4:
				choice = 0;
				check = 0;
				scanf("%*[^\n]%*c");
				printf("Enter a number:\n");
				scanf("\n%d", &num);
				while(num<1){
					scanf("%*[^\n]%*c");
					printf("Only positive number is allowed, please try again:\n");
					scanf("\n%d", &num);
				}
				
				if(num == 1){
					printf("The circle remains incomplete.\n");
					break;
				}

				temp = num/2;
				for(int i=2; i<=temp;i++){ //one is not needed to check, becuase everything can be devided by 1
					if(!(num%i)){
						printf("The circle remains incomplete.\n");
						check=1;
						break;
					}
				}

				if(check){
					printf("The circle remains incomplete.\n");
					break;
				}

				temp = (num%10)*10 + num/10; //swtiching numbers around
				num = temp;
				temp/=2;
				for(int i=2; i<=temp;i++){
					if(!(num%i)){
						printf("The circle remains incomplete.\n");
						check=1;
						break;
					}
				}
				
				if(!check){
					printf("This number completes the circle of joy!\n");
				}				
				break;

			case 5:
				choice = 0;
				scanf("%*[^\n]%*c");
				printf("Enter a number:\n");
				scanf("\n%d",&num);
				while(num<1){
					scanf("%*[^\n]%*c");
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}

				temp = 0;
				printf("Between 1 and %d only these numbers bring happiness:",num);
				for(int i=1; i<=num;i++){
					check = i;
					while(check != 58 && check != 1){ 
						while(check>0){
							digit = check%10;
							temp += digit*digit;
							check/=10;
						}
						check = temp;
						temp=0;
					}

					if(check == 1){
						printf(" %d",i);
					}
				}
				printf("\n");
				
				break;

			case 6:
				choice = 0;
				cheer = 0;
				smile = 0;
				printf("Enter a smile and cheer number:\n");
				checker = scanf("\nsmile: %d , cheer: %d",&smile,&cheer);
				while(checker != 2 || smile == cheer){
					scanf("%*[^\n]%*c");
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					checker = scanf("\nsmile: %d , cheer: %d",&smile,&cheer);
				}
				printf("Enter maximum number for the festival:\n");
				scanf("%d",&num);
				while(num<1){
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d",&num);
				}
				for(int i=1; i<=num;i++){
					if(!(i%smile) && !(i%cheer)) {
						printf("Festival!\n");
					} else if(!(i%smile)){
						printf("Smile!\n");
					} else if(!(i%cheer)){
						printf("Cheer!\n");
					}else{
						printf("%d\n",i);
					}
				}
				break;

			case 7:
				printf("Thank you for your journey through Numeria!\n");
				break;

			default:
				printf("This option is not available, please try again.\n");
		}
	}while(choice>7 || choice<1);
	
	return 0;
}
