class Employee{
private:
    char name[50];
    char departmentName[50];
    short age;
    int salary;
public:
    Employee();
    Employee(char *name, char *departmentName, short age, int salary);

public:
    const char *getName() const;
    const char *getDepartmentName() const;
    short getAge() const;
    int getSalary() const;

    bool setName(char* name);
    bool setDepartmentName(char* name);
    void setAge(short age);
    void setSalary(int salary);

    void printData();
};
