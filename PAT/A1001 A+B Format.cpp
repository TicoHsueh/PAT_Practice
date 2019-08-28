#include "bits/stdc++.h"
#include "stdlib.h"
using namespace std;
char res[10086];

void charParse(int n)
{
    int dir = 0;
    n = abs(n);
    while(n!=0)
    {
        res[dir] = n%10+'0';
        n/=10;
        dir++;
    }
    reverse(res,res+strlen(res));
}

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        memset(res,'\0',sizeof(res));
        if(a+b==0)
        {
            printf("0\n");
            continue;
        }
        charParse(a+b);
        if(a+b<0)
            printf("-");
        int dir = 0,len = strlen(res);
        if(len>3)
        {
            if(len%3==0){
                for(int i=0; i<len; i++)
                {
                    if(i%3==0&&i!=len-1&&i!=0)
                        printf(",");
                    printf("%c",res[i]);
                }
            } else{
                for(int i=0; i<len%3; i++)
                    printf("%c",res[i]);
                printf(",");
                dir = 0;
                for(int i=len%3; i<len; i++)
                {
                    dir++;
                    printf("%c",res[i]);
                    if(dir%3==0&&i!=len-1)
                        printf(",");
                }
            }
        }
        else//<=3
        {
            for(int i=0; i<len; i++)
                printf("%c",res[i]);
        }
        printf("\n");
    }
    return 0;
}




/*
import java.util.Scanner;

public class Main {
	public static boolean flag = false;
	public static String add(int a, int b) {
		String reString = null;
		if(a+b<0) {
			reString = (-(a+b))+"";
			flag = true;
		}else {
			reString = (a+b)+"";
		}
		return reString;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int a, b,l;
		String reString, result;
		while (scanner.hasNext()) {
			result = "";
			a = scanner.nextInt();
			b = scanner.nextInt();
			reString = add(a, b);
			l = reString.length();
			if(flag)
				System.out.print('-');
			for (int i = l - 1; i >= 0; i--) {
				result += reString.charAt(i);
				if ((reString.length() - i) % 3 == 0 && i != 0) {
					result += ',';
				}
			}

			for (int i = result.length() - 1; i >= 0; i--) {
				System.out.print(result.charAt(i));
			}
			System.out.println();
			flag = false;
		}
	}
}

*/
