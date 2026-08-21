class AverageGrade { 
public static void main(String ar [])
{
int math = 80;
int sci = 85;
int his = 90;

int average = (math + sci + his) /3;

System.out.println("Average marks :"+average);

if (average >= 90)
{
System.out.println("Grade: A");
}
else if (average >= 70 )
{
System.out.println("Grade: B");
}
else if (average >= 50)
{
System.out.println("Grade: C");
}
else if (average >= 30)
{
System.out.println("Grade: D");
}

}

}