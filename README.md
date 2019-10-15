# bsanzana_AED_guia4-u2
guia4-u2

Programa de Arbol Binario de busqueda.
El programa necesita tener el paquete graphiz, el cual el usuario debe instalar para poder vizualizar los grafos.
El programa se puede iniciar, estando en la carpeta del "ej1" y abrir una terminal y escribir ./Programa.

Lo más complicado ha sido implementar la eliminación de un nodo que tenga 2 hijos, por lo mismo comentare de aquello. Lo primero encontrar el nodo a eliminar (nEliminar), se guarda la rama derecha (nAux_der) del nodo nEliminar, luego el nEliminar se iguala a nOtro, que es un nodo que apunta a lo mismo de nEliminar, entonces luego se deletea nOtro, ahora se recorre toda la rama derecha para encontrar un máximo, el cual se guarda en nAux_derMax y el hijo derecho del nodo nAux_derMax será NULL, y ahí se conecta la rama derecha guardada en nAux_der.

Lo comentado anteriormente fue lo más complicado, pero si se necesita explicar otra cosa del codigo, por favor pedir el comentario.
