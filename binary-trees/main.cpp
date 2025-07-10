#include <cstdio>
// Extrclase BIS08
// Estructura de Datos - Árboles Binarios
// Universidad Latina de Costa Rica
// Autor: Rodolfo Meneses Leal
// Fecha: 10-07-2025

struct TreeNode {

    int value;

    //Las siguientes variables usan un * porque son punteros a otros nodos
    //Esto permite que cada nodo tenga un hijo izquierdo y un hijo derecho
    TreeNode* left;
    TreeNode* right;

    //Constructor para inicializar el nodo con un valor y punteros nulos
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Función para insertar un nuevo valor en el árbol
// Se usa * en TreeNode* para indicar que es un puntero a un nodo
TreeNode* insert(TreeNode* root, int value){

    // Si el arbol esta vacio, se crea un nuevo nodo y se retorna.
    if(root == nullptr)
        return new TreeNode(value);

    // Si el valor que se pasa como parametro es menor que el valor 
    // que tiene el nodo raiz pasado por paramentro entonces se inserta 
    // en el subárbol izquierdo, de lo contrario en el izquierdo. 
    if(value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    // Se retorna el nodo raiz actualizado
    return root;
    
}

void inorder(TreeNode* node){
    if (node == nullptr) return;

    // Recorrido en orden:
    // 1. Izquierda, 
    // 2. Raíz
    // 3. Derecha

    inorder(node->left);            // 1
    printf("%d ", node->value);     // 2
    inorder(node->right);           // 3

}

void preorder(TreeNode* node){
    if (node == nullptr) return;

    // Recorrido en preorden:
    // 1. Raíz,
    // 2. Izquierda,
    // 3. Derecha

    printf("%d ", node->value);     // 1
    preorder(node->left);           // 2
    preorder(node->right);          // 3
}

void postorder(TreeNode* node){
    if (node == nullptr) return;

    // Recorrido en postorden:
    // 1. Izquierda,
    // 2. Derecha,
    // 3. Raíz

    postorder(node->left);          // 1
    postorder(node->right);         // 2
    printf("%d ", node->value);     // 3

}

int main(){

    // Variables para el menú
    int choice;
    bool exit = false;
    TreeNode* root = nullptr;

    printf("\n");
    printf("Extraclase \n");
    printf("ULatina | BIS08 Estructura de Datos \n\n");

    while(!exit){

        printf("------------- Menu -------------\n");
        printf("1. Insertar elementos en el árbol \n");
        printf("2. Eleguir el tipo de recorrido a realizar \n");
        printf("Seleccione una opcion: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                int value;    
                printf("Insertar elementos en el árbol\n");
                printf("Ingrese un valor a insertar: ");
                scanf("%d", &value);
                printf("Valor %d insertado en el árbol🌳.\n", value);
                root = insert(root, value);
                break;
            case 2:
            int choice;
                printf("Eleguir el tipo de recorrido a realizar\n");
                printf("1. Recorrido en orden (Inorder) \n");
                printf("2. Recorrido en preorden (Preorder) \n");
                printf("3. Recorrido en postorden (Postorder) \n");
                printf("Seleccione el tipo de recorrido: ");
                scanf("%d", &choice);

                switch(choice){
                    case 1:
                        printf("Recorrido en orden seleccionado.\n");
                        inorder(root);
                        break;
                    case 2:
                        printf("Recorrido en preorden seleccionado.\n");
                        preorder(root);
                        break;
                    case 3:
                        printf("Recorrido en postorden seleccionado.\n");
                        postorder(root);
                        break;
                    default:
                        printf("Opción no válida. Intente de nuevo.\n");
                }
                printf("\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
        printf("\n");
    }
}