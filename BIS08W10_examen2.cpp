#include <cstdio>
#include <algorithm>
// BIS08 - Examen 2
// Estructura de Datos - Análisis de Árboles Binarios
// Universidad Latina de Costa Rica
// Autor: Rodolfo Meneses Leal
// Fecha: 23-07-2025

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor para inicializar el nodo
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Función para insertar un nuevo valor en el árbol
TreeNode* insert(TreeNode* root, int value){
    if(root == nullptr)
        return new TreeNode(value);

    if(value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Función para calcular la altura del árbol
int calculateHeight(TreeNode* node){
    // Caso base: si el nodo es nulo, la altura es 0
    if(node == nullptr)
        return 0;
    
    // Calculamos la altura de los subárboles izquierdo y derecho
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    
    // La altura del árbol es 1 + la altura máxima de sus subárboles
    // El +1 cuenta el nodo actual (donde estamos parados)
    return 1 + std::max(leftHeight, rightHeight);
}

// Función para contar las hojas (leaf nodes)
int countLeaves(TreeNode* node){
    // Si el nodo es nulo, no hay hojas
    if(node == nullptr)
        return 0;
    
    // Una hoja es un nodo que NO tiene hijos (ni izquierdo ni derecho)
    if(node->left == nullptr && node->right == nullptr)
        return 1; // Este nodo es una hoja
    
    // Si no es una hoja, contamos las hojas en sus subárboles
    return countLeaves(node->left) + countLeaves(node->right);
}

// Función para mostrar las hojas del árbol
void printLeaves(TreeNode* node){
    if(node == nullptr)
        return;
    
    // Si es una hoja, la imprimimos
    if(node->left == nullptr && node->right == nullptr){
        printf("%d ", node->value);
        return;
    }
    
    // Si no es hoja, buscamos en los subárboles
    printLeaves(node->left);
    printLeaves(node->right);
}

// Recorrido en preorden: Raíz -> Izquierda -> Derecha
void preorder(TreeNode* node){
    if(node == nullptr) return;
    
    printf("%d ", node->value);    // 1. Raíz
    preorder(node->left);          // 2. Izquierda
    preorder(node->right);         // 3. Derecha
}

// Recorrido en postorden: Izquierda -> Derecha -> Raíz
void postorder(TreeNode* node){
    if(node == nullptr) return;
    
    postorder(node->left);         // 1. Izquierda
    postorder(node->right);        // 2. Derecha
    printf("%d ", node->value);    // 3. Raíz
}

int main(){
    int choice;
    bool exit = false;
    TreeNode* root = nullptr;

    printf("\n=== Análisis de Árboles Binarios ===\n");
    printf("BIS08 | Estructura de Datos | Examen 2\n\n");

    while(!exit){
        printf("------------- Menu Principal -------------\n");
        printf("1. Insertar elementos en el árbol\n");
        printf("2. Análisis del árbol\n");
        printf("3. Recorridos del árbol\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                int value;
                printf("=== Insertar elementos en el árbol ===\n");
                printf("Ingrese un valor a insertar: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Valor %d insertado en el árbol.\n", value);
                break;
            case 2:
                if(root == nullptr){
                    printf("El árbol está vacío. Inserte algunos valores primero.\n");
                    break;
                }
                
                printf("=== Análisis del Árbol ===\n");
                printf("Información del árbol:\n");
                printf("   Raíz del árbol: %d\n", root->value);
                printf("   Altura del árbol: %d\n", calculateHeight(root));
                printf("   Número de hojas: %d\n", countLeaves(root));
                printf("   Hojas del árbol: ");
                printLeaves(root);
                printf("\n");
                break;
            case 3:
                if(root == nullptr){
                    printf("El árbol está vacío. Inserte algunos valores primero.\n");
                    break;
                }
                
                int traversalChoice;
                printf("=== Recorridos del Árbol ===\n");
                printf("1. Recorrido en preorden (Preorder)\n");
                printf("2. Recorrido en postorden (Postorder)\n");
                printf("Seleccione el tipo de recorrido: ");
                scanf("%d", &traversalChoice);
                printf("\n");
                
                switch(traversalChoice){
                    case 1:
                        printf("Recorrido en preorden: ");
                        preorder(root);
                        printf("\n");
                        printf("Orden: Raíz → Izquierda → Derecha\n");
                        break;
                    case 2:
                        printf("Recorrido en postorden: ");
                        postorder(root);
                        printf("\n");
                        printf("Orden: Izquierda → Derecha → Raíz\n");
                        break;
                    default:
                        printf("Opción no válida.\n");
                }
                break;
            case 4:
                exit = true;
                printf("Fin del examen\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
        printf("\n");
    }

    return 0;
}