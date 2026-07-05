#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define DATAFILE "students.dat"

typedef struct {
    int id;
    char name[MAX_NAME];
    int age;
    float gpa;
} Student;

void clear_stdin(){ int c; while((c=getchar())!='\n' && c!=EOF){} }

Student *load_students(size_t *count){
    FILE *f = fopen(DATAFILE, "rb");
    if(!f){ *count = 0; return NULL; }
    fseek(f,0,SEEK_END);
    long sz = ftell(f);
    rewind(f);
    *count = sz / sizeof(Student);
    if(*count == 0){ fclose(f); return NULL; }
    Student *arr = malloc((*count) * sizeof(Student));
    if(!arr){ fclose(f); *count = 0; return NULL; }
    fread(arr, sizeof(Student), *count, f);
    fclose(f);
    return arr;
}

int save_students(Student *arr, size_t count){
    FILE *f = fopen(DATAFILE, "wb");
    if(!f) return 0;
    fwrite(arr, sizeof(Student), count, f);
    fclose(f);
    return 1;
}

int next_id(Student *arr, size_t count){
    int max = 0;
    for(size_t i=0;i<count;i++) if(arr[i].id > max) max = arr[i].id;
    return max + 1;
}

void add_student(){
    size_t count;
    Student *arr = load_students(&count);
    Student s;
    s.id = next_id(arr, count);
    printf("Enter name: ");
    if(!fgets(s.name, MAX_NAME, stdin)) { free(arr); return; }
    s.name[strcspn(s.name, "\n")] = '\0';
    printf("Enter age: "); if(scanf("%d", &s.age)!=1){ clear_stdin(); free(arr); return; }
    printf("Enter GPA: "); if(scanf("%f", &s.gpa)!=1){ clear_stdin(); free(arr); return; }
    clear_stdin();
    Student *newarr = realloc(arr, (count+1)*sizeof(Student));
    if(!newarr) { free(arr); printf("Memory error\n"); return; }
    newarr[count] = s;
    if(!save_students(newarr, count+1)) printf("Failed to save.\n");
    else printf("Student added with ID %d\n", s.id);
    free(newarr);
}

void list_students(){
    size_t count; Student *arr = load_students(&count);
    if(!arr || count==0){ printf("No records.\n"); free(arr); return; }
    printf("%-5s %-20s %-5s %-5s\n","ID","Name","Age","GPA");
    for(size_t i=0;i<count;i++){
        printf("%-5d %-20s %-5d %-5.2f\n", arr[i].id, arr[i].name, arr[i].age, arr[i].gpa);
    }
    free(arr);
}

Student *find_by_id(size_t *count, int id){
    Student *arr = load_students(count);
    if(!arr) return NULL;
    for(size_t i=0;i<*count;i++) if(arr[i].id==id) return arr; // return pointer to allocated array
    free(arr);
    return NULL;
}

void search_student(){
    size_t count; Student *arr = load_students(&count);
    if(!arr || count==0){ printf("No records.\n"); free(arr); return; }
    int id; printf("Enter ID to search: "); if(scanf("%d", &id)!=1){ clear_stdin(); free(arr); return; }
    for(size_t i=0;i<count;i++){
        if(arr[i].id==id){
            printf("Found: ID=%d Name=%s Age=%d GPA=%.2f\n", arr[i].id, arr[i].name, arr[i].age, arr[i].gpa);
            free(arr); clear_stdin(); return;
        }
    }
    printf("Not found.\n");
    free(arr); clear_stdin();
}

void update_student(){
    size_t count; Student *arr = load_students(&count);
    if(!arr || count==0){ printf("No records.\n"); free(arr); return; }
    int id; printf("Enter ID to update: "); if(scanf("%d", &id)!=1){ clear_stdin(); free(arr); return; }
    for(size_t i=0;i<count;i++){
        if(arr[i].id==id){
            clear_stdin();
            printf("Enter new name (blank to keep): ");
            char buf[MAX_NAME]; if(fgets(buf, MAX_NAME, stdin)){
                buf[strcspn(buf, "\n")]='\0'; if(strlen(buf)) strncpy(arr[i].name, buf, MAX_NAME);
            }
            printf("Enter new age (0 to keep): "); int age; if(scanf("%d", &age)==1 && age>0) arr[i].age = age;
            printf("Enter new GPA (-1 to keep): "); float g; if(scanf("%f", &g)==1 && g>=0) arr[i].gpa = g;
            clear_stdin();
            if(save_students(arr, count)) printf("Updated.\n"); else printf("Failed to save.\n");
            free(arr); return;
        }
    }
    printf("Not found.\n"); free(arr); clear_stdin();
}

void delete_student(){
    size_t count; Student *arr = load_students(&count);
    if(!arr || count==0){ printf("No records.\n"); free(arr); return; }
    int id; printf("Enter ID to delete: "); if(scanf("%d", &id)!=1){ clear_stdin(); free(arr); return; }
    size_t idx = SIZE_MAX; for(size_t i=0;i<count;i++) if(arr[i].id==id) { idx = i; break; }
    if(idx==SIZE_MAX){ printf("Not found.\n"); free(arr); clear_stdin(); return; }
    for(size_t i=idx;i+1<count;i++) arr[i]=arr[i+1];
    if(count-1==0){ remove(DATAFILE); free(arr); printf("Deleted.\n"); clear_stdin(); return; }
    if(save_students(arr, count-1)) printf("Deleted.\n"); else printf("Failed to save.\n");
    free(arr); clear_stdin();
}

int main(){
    for(;;){
        printf("\nStudent Record Management\n1. Add\n2. List\n3. Search\n4. Update\n5. Delete\n6. Exit\nChoose: ");
        int choice; if(scanf("%d", &choice)!=1){ clear_stdin(); continue; }
        clear_stdin();
        switch(choice){
            case 1: add_student(); break;
            case 2: list_students(); break;
            case 3: search_student(); break;
            case 4: update_student(); break;
            case 5: delete_student(); break;
            case 6: printf("Bye.\n"); return 0;
            default: printf("Invalid.\n");
        }
    }
    return 0;
}
