//
//  main.cpp
//  |JANA|
//
//  Create by Alejandro S. Leal && Natalia A. on 5/10/2020
//
//  Copyright © 2020 aslbank.com. All rights reserved.
//

//  Librerias
#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

//Estructura Objetos
struct DISP{
    string name;
    string brand;
    string position;
    
    string vol;
    string estate;
    string chanel;
    string lumino;
};

//Estructura usuarios
struct USER{
    int id;
    string name;
    string email;
    string password;
    string Profession;
    string bornDate;
    string sex;
    DISP dispo[4];
    bool auth;
};

//Declaracion de Funciones de Usaurio
bool welcome();
bool Create_Acount(bool NotUser, USER userVect[9]);
USER login(USER user,USER userVect[9]);
void Security(USER user,USER userVect[9]);

//Funciones de Funcionalidades de la app
void menu(USER user, USER Func_login,USER userVect[9]);
void func_agregar_dispositivos(USER user,USER userVect[9]);
void func_eliminar_dispositivos(USER user,USER userVect[9]);
void func_listar_dispositivos(USER user,USER userVect[9]);
void func_modificar_caracteristicas_dispositivos(USER user,USER userVect[9]);
void func_modificar_funcionalidades_dispositivos(USER user,USER userVect[9]);

//Funcion Principal
int main()
{
    //Vect+Structuta de Usuarios + dispositivos
    USER userVect[9];
    USER user;

    Security(user,userVect);
            

    return 0;
}

/*

Funcion que pegunta al usuario
es nuevo o existente retornando
su respuesta (yes/no).

*/

bool welcome()
{
    //Se inicializa una variables string para almacenar la respesta
    //Se inicializa variable booleana
    string acount;
    bool estado;

    //Se imprime un mensaje de bienvenida
    system("clear");
    cout<< "\t\t\t--------------------"<<endl;
    cout<< "\t\t\t-| Welcome to JANA |-"<<endl;
    cout<< "\t\t\t---------------------"<<endl;
    cout<< "\t\t\t                    "<<endl;
    cout<< "\t\t\t                    "<<endl;

    //Se pregunnta si tiene cuenta o no
    cout<< " -| Hi, you have acount? (yes/no): ";
    //Se alamacena la respuesta en acount
    cin>>acount;
    cout<<"  "<<endl;


    //Se evalua la respuesta del usuario para saber si es nuevo o existente.
    if(acount=="yes"||acount=="YES"||acount=="y"||acount=="Y")
    {
        //En caso de que sea usuario activo.
        estado=true;
        cout<<" -| Oh you are a Active User!!!"<<endl;
        cout<<"  "<<endl;
    }
    else
    {
        //En caso de que sea un nuevo usuario.
        estado=false;
    }

    //Se retorna el resultado de la evaluacion.
    return estado;
}

//Funcion que crea Usuarios
bool Create_Acount(bool NotUser,USER userVect[9])
{
    //INICIALIZACION DE VARIABLES INTERNAS
    int CountUsers= 0;
    string change= "j";

    //CONTROL DEL PROGRAMA
    if (NotUser==false)//SI NO ES USUARIO ENTRA, DE LO CONTRARIO NO.
    {
        bool state=false;
        cout<<" -| !Oh you need create a Acount!"<<endl;;
        cout<<" -| Very well now i will help to create your user."<<endl;
        cout<<"  "<<endl;
        
        //CICLO GUARDA LA INFORMACION DE EL NUEVO USUARIO AL USERVECT.
        for(CountUsers=CountUsers;state==false;CountUsers++)
        {
            //REQUISITO DE INFORMACION REQUERIDA PARA LA CREACION DE USUARIO.
            userVect[CountUsers].id=CountUsers;//CONTADOR DE USUARIOS.
            
            //LE DICE AL USUARIO EL NUMERO DE CLIENTE QUE SERA.
            cout<<" -| Now you are a User: "<<userVect[CountUsers].id<<endl;
            cout<<"  "<<endl;
            
            //SE REALIZA LA CAPTACION DE INFORMACION DE USUARIO.
            cout<<" -| First: Give Me Your First Name and Last Name: ";
            cin>>userVect[userVect[CountUsers].id].name;//NOMBRE
            cout<<"  "<<endl;
                
            cout<<" -| Second: Give Me Your Javeriana Email: ";
            cin>>userVect[userVect[CountUsers].id].email;//EMAIL
            cout<<"  "<<endl;
                       
            cout<<" -| Third: Give Me Your Profession: ";
            cin>>userVect[userVect[CountUsers].id].Profession;//PROFESSION
            cout<<"  "<<endl;
                
            cout<<" -| Quarter: Give Me Your Sex (M/F): ";
            cin>>userVect[userVect[CountUsers].id].sex;//SEXO
            cout<<"  "<<endl;
                
            cout<<" -| Fifth: Give Me Your Born Date(DD/MM/AA): ";
            cin>>userVect[userVect[CountUsers].id].bornDate;//AÑO DE NACIMIENTO
            cout<<"  "<<endl;
                
            cout<<" -| Sixth: Create a Password: ";
            cin>>userVect[userVect[CountUsers].id].password;//CONTRASEÑA
            cout<<"  "<<endl;
            
            //SE LIMPIA LA ANTERIOR INFORMACION
            system("clear");
            
            //INICIA LA VERIFICACION DE LOS DATOS ANTERIORMENTE INGRESADOS
            
            cout<<" -| "<<userVect[userVect[CountUsers].id].name<<" Check that it is the correct information. "<<endl;
            
            cout<<" -| Now you are a User: "<<userVect[CountUsers].id<<endl;
            cout<<"  "<<endl;
            
            cout<<" -| First: Your First Name and Last Name: "
                <<userVect[userVect[CountUsers].id].name;
                cout<<"  "<<endl;
            
                cout<<" -| Second: Your Javeriana Email: "
                <<userVect[userVect[CountUsers].id].email;
                cout<<"  "<<endl;
            
                cout<<" -| Third: Your Profession: "
                <<userVect[userVect[CountUsers].id].Profession;
                cout<<"  "<<endl;
            
                cout<<" -| Quarter: Your Sex (M/F): "
                <<userVect[userVect[CountUsers].id].sex;
                cout<<"  "<<endl;
            
                cout<<" -| Fifth: Your Born Date(DD/MM/AA): "
                <<userVect[userVect[CountUsers].id].bornDate;
                cout<<"  "<<endl;
            
                cout<<" -| Sixth: Your Password: "
                <<userVect[userVect[CountUsers].id].password;
                cout<<"  "<<endl;
            
            ///ENCASO DE SER POSITIVO SE RE INICIA EL CICLO DE LO CONTRARIO
            ///SE SALE DEL CICLO Y LA FUNCION RETORNA VERDADERA.
            cout<<" "<<endl;
            cout<<" -| Do you want to change something? (yes/no): ";
            cin>>change;
            cout<<" "<<endl;
            
            ///ANALIZADOR DE LA RESPUESTA
            if(change=="y" || change=="yes" || change=="Y" || change=="YES")
            {
                ///LIMPIA LA  ANTERIOR INFORMACION
                system("clear");
                
                ///CONTROLADORES
                state=false;//NO CIERRA EL CICLO.
                return false;//RETORNA FALSE LA FUNCION

            }else{
                
                ///LIMPIA LA  ANTERIOR INFORMACION
                system("clear");
                CountUsers+=1;///SE AUMENTA EL CONTADOR DEL USUARIO EN 1 +
                
                ///CONTROLADORES
                state=true;//CIERRA EL CICLO.
                
            }

        }//FOR END

        cout<<" -| Successful account process!!!"<<endl;
        cout<<" "<<endl;
        return true;//RETORNA VERDADERO LA FUNCION
        
    }//IF END
    
    return true;//RETORNA VERDADERO LA FUNCION
}

///VERIFICA SI UN USUARIO ESTA REGISTRADO.
USER login(USER user,USER userVect[9])
{
    string email,password,again;
    
        cout<<" -| Give me your Javeriana email: ";
        cin>>email;
        cout<<" -| Give me your password: ";
        cin>>password;
        cout<<" "<<endl;
    
    //RECORRE EL VECTOR DE USUARIOS BUSCANDO SU PAR
    for(int i = 0; i<9; i++)
    {
        //CUANDO ENCUANTRA UN EMAIL EN EL VECTOR DEL EMAIL INGRESADO ENTONCES
        //VERIFICA SI LA CONTRASEÑA ES DE IGUALFORMA CORRECTA, PERO SI NO LO ES
        //SOLO RETORNA QUE LA AUTENTIFICACION ES FALSA A LA FUNCION SECURE
        if(userVect[i].email==email)
        {
            if(userVect[i].password==password)
            {
                user.id= i;//POSICION DEL USUARIO ES EL VECTOR USUARIOS
                userVect[i].id= user.id;
                userVect[i].auth= true;
                user.auth= userVect[i].auth;
                cout<<" -| Authentication Success!"<<endl;
                return user;
                
            }else{user.auth=false;}
            
        }else{
            
            user.auth=false;
            system("clear");
        }
       
    }

    return user;

}


void Security(USER user,USER userVect[9])
{
    //Variables de Retorno de funciones
    bool Func_Welcome=false;
    bool Func_Create_Acount = false;
    USER Func_login;
    
    //Se limpia la terminal de la informacion anterior
    system("clear");
    
    //Inicio de la logica de programa
    Func_Welcome= welcome();//Retorna si ya es usuario o no
    
    
    if(Func_Welcome==true)//Si ya es usuario ejecuta el ciclo de aut para login
    {
        //Ciclo se repite solo 4 veces si la aut no es exitosa
        //Si se exede los intentos cierra el programa
        Func_login.auth = false;
        for(int i= 0; i<= 3 && Func_login.auth == false; i++)//Maximo 4 intentos de login
        {
            
            cout<<" -| Now Login"<<endl;
            cout<<" "<<endl;
            Func_login=login(user, userVect);//Retorna true si el login es exitoso
            
            //Si la aut del user en el login es positiva envia al usuario a su menu
            if(Func_login.auth==true)
            {
                system("clear");
                menu(user,Func_login,userVect);
                cout<<" "<<endl;
                
            }else{//De lo contrario el programa cuenta los intentos para hacer falsa el if de los intentos del login
                
                system("clear");//Limpiamos los anteriores intentos de la pantalla
                cout<<" "<<endl;
                cout<<"Te quedan: "<<4-(i+1)<<" Intentos"<<endl<<endl;
                
                if(i==3)//Se cierra el programa cuando se alcancen el maximo de intentos
                {
                    cout<<" "<<endl;
                    cout<<"Reinica el programa"<<endl<<endl;
                    cout<<" "<<endl;
                }
                
            }
        }

        
    }else{//Caso cuando es un usuario nuevo y no esta registrado o es el primer inicio del programa
        
        //Funcion Crea usuario nuevo y retorna un booleano para el caso exitoso
        Func_Create_Acount=Create_Acount(Func_Welcome, userVect);
        
        //Condicion para evaluar si el usuario ha sido correcatemente creado
        if(Func_Create_Acount==true)
        {
            //Ciclo se repite solo 4 veces si la aut no es exitosa
            //Si se exede los intentos cierra el programa.
            Func_login.auth = false;
            
            ///CICLO QUE SE REPITE 3 VECES MAS SI EL LOGIN NO FUE EXITOSO
            for(int i= 0; i<= 3 && Func_login.auth == false; i++)
            {
                cout<<" -| Now Login"<<endl;
                cout<<" "<<endl;
                Func_login=login(user, userVect);
                
                //CASO CUANDO EL LOGIN FUE UN EXITO SE ENVIA AL MENU CORRESPONDIENTE DEL USUARIO
                if(Func_login.auth==true)
                {
                    system("clear");///SE LIMPIA LA INFORMACION ANTERIOR
                    menu(user,Func_login,userVect);
                    cout<<" "<<endl;
                    
                }else{//DE LO CONTRAARIO CUENTA LOS INTENTOS PARA LUEGO CERRAR EL CICLO Y EL PROGRAMA.
                    
                    system("clear");///LIMPIA LA ANTERIOR INFORMACION
                    cout<<" "<<endl;
                    cout<<"Te quedan: "<<4-(i+1)<<" Intentos"<<endl<<endl;///CONTADOR DE INTENTOS
                    
                    if(i==3)//CUANDO HA EXEDIDO LOS INTENTOS SE CIERRA
                    {
                        cout<<" "<<endl;
                        cout<<"Reinica el programa"<<endl<<endl;
                        cout<<" "<<endl;
                    }
                    
                }
            }
            
        }else{
              //Caso para cuando el usuario no se ha creado con exito
             //Se repite todo desde el principio sin borrar los anteriores usuarios
            //Que ya estubiran registrados.
            Security(user, userVect);
        }
    }
}

void menu(USER user,USER Func_login, USER userVect[9]){
    
    ///VARIABLE INTERNA DE CONTROL
    int opcion;
    
    //BUSCAR EL USUARIO POR SU ID EN EL USERVECT PARA GURADAR TODO LOS QUE SE HAGA EN ESTE MENU
    for(int i= 0; i < 9; i++)///MAXIMO 9 USUARIOS
    {
        //SI SOLO SI EL USUARIO ID QUE SE HA LOGIADO ES IGUAL AL CONTADOR DEL CICLO SE MUESTRA EL MENU CORRESPONDIENTE A ESE USUARIO
        if(i == Func_login.id)
        {
            
            cout<<" -| Welcome to JANA Menu "<<userVect[Func_login.id].name<<endl;
            cout<<" -|"<<endl;
            cout<<" -| 1. Agregar Dispositivos"<<endl;
            cout<<" -| 2. Eliminar Dispositivos"<<endl;
            cout<<" -| 3. Listar Dispositivos"<<endl;
            cout<<" -| 4. Modificar Caracteristicas Dispositivos"<<endl;
            cout<<" -| 5. Modificar Funcionalidades Dispositivos"<<endl;
            cout<<" -| 6. Login Whit other Account User"<<endl<<endl;
            
            cout<<" -| Type the option do you want to access (1 to 5): ";
            cin>>opcion;
            cout<<" "<<endl;
            
            switch(opcion){
                case 1:
                    cout<<" -| Opcion: Agregar Dispositivos"<<endl;
                    func_agregar_dispositivos(Func_login,userVect);
                    break;
                case 2:
                    cout<<" -| Opcion: Eliminar Dispositivos"<<endl;
                    func_eliminar_dispositivos(Func_login,userVect);
                    break;
                case 3:
                    cout<<" -| Opcion: Listar Dispositivos"<<endl;
                    func_listar_dispositivos(Func_login,userVect);
                    break;
                case 4:
                    cout<<" -| Opcion: Modificar Caracteristicas Dispositivos"<<endl;
                    func_modificar_caracteristicas_dispositivos(Func_login,userVect);
                    break;
                case 5:
                    cout<<" -| Opcion: Modificar Funcionalidades Dispositivos"<<endl;
                    func_modificar_funcionalidades_dispositivos(Func_login,userVect);
                    break;
                case 6:
                cout<<" -| Opcion: Login whit other account user"<<endl;
                        Security(user,userVect);
                        break;
                default:
                    cout<<" -| Ingrese un numero de opcion valido"<<endl;
                    break;
            }
            
        }
    }
    
}

//Funcionalidades del Menu
//userVect[user.id].dispo[0].name=Televisor .... Lampara.
void func_agregar_dispositivos(USER user, USER Func_login, USER userVect[9])
{
    int numeroDispo=0;
    char tipo='f',volver;
    //recorrer hasta llegar al id de usuario que solucita la funcion
    
    //Menu Interno
    cout<<" -| Dispositivo de Tipo:"<<endl;
    cout<<" "<<endl;
    
    cout<<" -| A -> Televisor "<<endl;
    cout<<" -| B -> Cerradura "<<endl;
    cout<<" -| C -> Cortina "<<endl;
    cout<<" -| D -> Lampara "<<endl;
    cout<<" -| E -> Volver al Menu inicial "<<endl;
    cout<<" "<<endl;
    
    cout<<" -| Selecciona un tipo: ";
    cin>>tipo;
    cout<<" "<<endl;
    
    cout<<" -| Nota: La capa gratitua solo pueden agregar 1 dispositivo por tipo :) "<<endl;
    cout<<" -| Nota: Si eliges el mismo tipo 2 veses queda guardado con la ultina configuracion "<<endl;
    cout<<" "<<endl;
    
    for(int i= 0;i < 9;i++)//Busca al Usuario en el vector
    {
        if(Func_login.id==i)//Extrae su indice para agregar la informacion de los dispositivos
        {
            cout<<" -| Agrega tu Dispositivo tipo: ";
             
            
            if(tipo=='A'||tipo=='a')
            {
                cout<<"Televisor"<<endl;
                cout<<"  "<<endl;
                
                cout<<" -| Nombre del Dispositivo: ";
                cin>>userVect[Func_login.id].dispo[0].name;
                cout<<"  "<<endl;
                
                cout<<" -| Marca del Dispositivo: ";
                cin>>userVect[Func_login.id].dispo[0].brand;
                cout<<"  "<<endl;
                
                cout<<" -| Posicion del Dispositivo: ";
                cin>>userVect[Func_login.id].dispo[0].position;
                cout<<"  "<<endl;
                
                //Funcionalidades de los Dispo
                
                cout<<" -| Volumen del Dispositivo (0 -> 10): ";
                cin>>userVect[Func_login.id].dispo[0].vol;
                cout<<"  "<<endl;
                
                cout<<" -| Canal del Dispositivo (0 -> 125): ";
                cin>>userVect[Func_login.id].dispo[0].chanel;
                cout<<"  "<<endl;
                
                cout<<" -| Estado del Dispositivo (Apagado/Prendido): ";
                cin>>userVect[Func_login.id].dispo[0].estate;
                cout<<"  "<<endl;
            
                userVect[Func_login.id].dispo[0].lumino="N/A";
                
                numeroDispo++;
                cout<<"Dispositivo Creado"<<endl;
                cout<<"  "<<endl;
                
                func_agregar_dispositivos(Func_login,userVect);
                
            }else{
                
                if(tipo=='B'||tipo=='b')
                {
                    cout<<" -| Dispositivo Tipo: Cerradura"<<endl;
                    cout<<"  "<<endl;
                    
                    cout<<" -| Nombre del Dispositivo: ";
                    cin>>userVect[Func_login.id].dispo[1].name;
                    cout<<"  "<<endl;
                    
                    cout<<" -| Marca del Dispositivo: ";
                    cin>>userVect[Func_login.id].dispo[1].brand;
                    cout<<"  "<<endl;
                    
                    cout<<" -| Posicion del Dispositivo: ";
                    cin>>userVect[Func_login.id].dispo[1].position;
                    cout<<"  "<<endl;
                    
                    cout<<" -| Estado del Dispositivo (Abierto/Cerrado): ";
                    cin>>userVect[Func_login.id].dispo[0].estate;
                    cout<<"  "<<endl;
                    
                    userVect[Func_login.id].dispo[0].vol="N/A";
                    userVect[Func_login.id].dispo[0].chanel="N/A";
                    userVect[Func_login.id].dispo[0].lumino="N/A";
                    
                    numeroDispo++;
                    
                    cout<<"Dispositivo Creado"<<endl;
                    cout<<"  "<<endl;
                    
                    func_agregar_dispositivos(Func_login,userVect);
                    
                }else{
                    
                    if(tipo=='C'||tipo=='c')
                    {
                        cout<<" -| Dispositivo Tipo: Cortina"<<endl;
                        cout<<"  "<<endl;
                        
                        cout<<" -| Nombre del Dispositivo: ";
                        cin>>userVect[Func_login.id].dispo[2].name;
                        cout<<"  "<<endl;
                        
                        cout<<" -| Marca del Dispositivo: ";
                        cin>>userVect[Func_login.id].dispo[2].brand;
                        cout<<"  "<<endl;
                        
                        cout<<" -| Posicion del Dispositivo: ";
                        cin>>userVect[Func_login.id].dispo[2].position;
                        cout<<"  "<<endl;
                        
                        cout<<" -| Estado del Dispositivo (Abierto/Cerrado): ";
                        cin>>userVect[Func_login.id].dispo[0].estate;
                        cout<<"  "<<endl;
                        
                        userVect[Func_login.id].dispo[0].vol="N/A";
                        userVect[Func_login.id].dispo[0].chanel="N/A";
                        userVect[Func_login.id].dispo[0].lumino="N/A";
                        
                        numeroDispo++;
                        
                        cout<<"Dispositivo Creado"<<endl;
                        cout<<"  "<<endl;
                        
                        func_agregar_dispositivos(Func_login,userVect);
                        
                    }else{
                        
                        if(tipo=='D'||tipo=='d')
                        {
                            cout<<" -| Dispositivo Tipo: Lampara"<<endl;
                            cout<<"  "<<endl;
                            
                            cout<<" -| Nombre del Dispositivo: ";
                            cin>>userVect[Func_login.id].dispo[3].name;
                            cout<<"  "<<endl;
                            
                            cout<<" -| Marca del Dispositivo: ";
                            cin>>userVect[Func_login.id].dispo[3].brand;
                            cout<<"  "<<endl;
                            
                            cout<<" -| Posicion del Dispositivo: ";
                            cin>>userVect[Func_login.id].dispo[3].position;
                            cout<<"  "<<endl;
                            
                            cout<<" -| Estado del Dispositivo (Abierto/Cerrado): ";
                            cin>>userVect[Func_login.id].dispo[0].estate;
                            cout<<"  "<<endl;
                            
                            cout<<" -| Luminosidad del Dispositivo (0 -> 10): ";
                            cin>>userVect[Func_login.id].dispo[0].lumino;
                            cout<<"  "<<endl;
                            
                            userVect[Func_login.id].dispo[0].vol="N/A";
                            userVect[Func_login.id].dispo[0].chanel="N/A";
                            
                            numeroDispo++;
                            cout<<"Dispositivo Creado"<<endl;
                            cout<<"  "<<endl;
                            
                            func_agregar_dispositivos(Func_login,userVect);
                            
                        }else{
                            if(tipo=='E'||tipo=='e')
                            {
                                system("clear");
                                menu(user,Func_login,userVect);
                            
                            }else{
                                
                                cout<<"  "<<endl;
                                cout<<"Tipo Incorrecto"<<endl;
                                cout<<"  "<<endl;
                                system("clear");
                                func_agregar_dispositivos(Func_login,userVect);
                            }
                        }
                    }
                }
            }
                
                
            if(numeroDispo==4)
            {
                cout<<"Ya copaste el limite de la capa gratis. Si no deseas cambiar"<<endl;
                cout<<"la configuracion de tus dispositivos o re escribirlos te sujiero"<<endl;
                cout<<"volver al menu inicial o pagar uns susbcripcion por el progrmama"<<endl;
                cout<<"Desea volver al menu inicial (S/n): "<<endl;
                cin>>volver;
                
                if(volver=='s'||volver=='S')
                {
                    system("clear");
                    menu(user,Func_login,userVect);
                    
                }else{
                    
                    system("clear");
                    func_agregar_dispositivos(Func_login,userVect);
                }
            }
            
        }
    }
}

void func_eliminar_dispositivos(USER Func_login,USER userVect[9]){

}

void func_listar_dispositivos(USER Func_login,USER userVect[9]){

}

void func_modificar_caracteristicas_dispositivos(USER Func_login,USER userVect[9]){

}

void func_modificar_funcionalidades_dispositivos(USER Func_login,USER userVect[9]){

}


