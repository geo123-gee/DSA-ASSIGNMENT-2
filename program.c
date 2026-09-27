#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 3
#define MAX_NAME 30
#define MAX_DEPARTMENTS 20

// Structure for a tree node
struct Node {
    char name[MAX_NAME];
    int childCount;
    struct Node* children[MAX_CHILDREN];
};

// Function to create a new node
struct Node* createNode(char name[]) {
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    newNode->childCount = 0;

    return newNode;
}

// Function to add a child to a node
void addChild(struct Node* parent, struct Node* child) {
    parent->children[parent->childCount] = child;
    parent->childCount++;
}

// Level-order traversal using a queue
void levelOrder(struct Node* root) {
    struct Node* queue[MAX_DEPARTMENTS];

    int front = 0;
    int rear = 0;

    if (root == NULL)
        return;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        printf("%s ", current->name);

        for (int i = 0; i < current->childCount; i++) {
            queue[rear++] = current->children[i];
        }
    }
}

// Linear Search
int linearSearch(char departments[][MAX_NAME],
                 int n,
                 char target[],
                 int* comparisons) {

    *comparisons = 0;

    for (int i = 0; i < n; i++) {

        (*comparisons)++;

        if (strcmp(departments[i], target) == 0)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(char departments[][MAX_NAME],
                 int n,
                 char target[],
                 int* comparisons) {

    int low = 0;
    int high = n - 1;

    *comparisons = 0;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        (*comparisons)++;

        if (strcmp(departments[mid], target) == 0)
            return mid;

        else if (strcmp(departments[mid], target) < 0)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

// Function to sort department names
void sortDepartments(char departments[][MAX_NAME], int n) {

    char temp[MAX_NAME];

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (strcmp(departments[j],
                       departments[j + 1]) > 0) {

                strcpy(temp, departments[j]);

                strcpy(departments[j],
                       departments[j + 1]);

                strcpy(departments[j + 1],
                       temp);
            }
        }
    }
}

int main() {

    // -------------------------------------
    // PART A: Construct the tree
    // -------------------------------------

    struct Node* CEO = createNode("CEO");
    struct Node* HR = createNode("HR");
    struct Node* Finance = createNode("Finance");
    struct Node* IT = createNode("IT");

    struct Node* Development = createNode("Development");
    struct Node* Testing = createNode("Testing");

    struct Node* Frontend = createNode("Frontend");
    struct Node* Backend = createNode("Backend");

    // Build the hierarchy
    addChild(CEO, HR);
    addChild(CEO, Finance);
    addChild(CEO, IT);

    addChild(IT, Development);
    addChild(IT, Testing);

    addChild(Development, Frontend);
    addChild(Development, Backend);

    // Display hierarchy
    printf("Level-order traversal:\n");

    levelOrder(CEO);

    printf("\n\n");


    // -------------------------------------
    // PART B: Department Searching
    // -------------------------------------

    char departments[MAX_DEPARTMENTS][MAX_NAME] = {
        "CEO",
        "HR",
        "Finance",
        "IT",
        "Development",
        "Testing",
        "Frontend",
        "Backend"
    };

    int n = 8;

    // Sort departments for binary search
    sortDepartments(departments, n);

    printf("Sorted departments:\n");

    for (int i = 0; i < n; i++) {
        printf("%s ", departments[i]);
    }

    printf("\n\n");


    // -------------------------------------
    // Search three departments
    // -------------------------------------

    char searches[3][MAX_NAME] = {
        "CEO",
        "Development",
        "Backend"
    };

    for (int i = 0; i < 3; i++) {

        int linearComparisons;
        int binaryComparisons;

        int linearResult =
            linearSearch(departments,
                         n,
                         searches[i],
                         &linearComparisons);

        int binaryResult =
            binarySearch(departments,
                         n,
                         searches[i],
                         &binaryComparisons);

        printf("Search: %s\n", searches[i]);

        if (linearResult != -1)
            printf("Linear Search: Found, Comparisons = %d\n",
                   linearComparisons);
        else
            printf("Linear Search: Not Found, Comparisons = %d\n",
                   linearComparisons);

        if (binaryResult != -1)
            printf("Binary Search: Found, Comparisons = %d\n",
                   binaryComparisons);
        else
            printf("Binary Search: Not Found, Comparisons = %d\n",
                   binaryComparisons);

        printf("\n");
    }

    return 0;
}
