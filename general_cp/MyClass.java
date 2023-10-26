package general_cp;
import java.util.Scanner;
public class MyClass
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        //int a=sc.nextInt();
        //System.out.println(a);
        Travel t[]=new Travel[3];
        for(int i=0;i<t.length;i++){
            int id=sc.nextInt();
            sc.nextLine();
            String n=sc.nextLine();
            String p=sc.nextLine();
            int pr=sc.nextInt();
            sc.nextLine();
            boolean f=sc.nextBoolean();
            t[i]=new Travel(id,n,p,pr,f);
        }
        int h=highest(t);
        System.out.println("The highest price="+h);
        
    }
    public static int highest(Travel ob[]){
        int s=0;
        for(int i=0;i<ob.length;i++){
            if(ob[i].getPrice()>s){
                s=ob[i].getPrice();
            }
        }
        return s;
    }
}

