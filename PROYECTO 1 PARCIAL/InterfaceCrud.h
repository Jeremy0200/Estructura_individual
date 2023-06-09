/***********************************************************************
 * Module:  InterfaceCrud.h
 * Author:  Milena
 * Modified: domingo, 4 de junio de 2023 12:32:50
 * Purpose: Declaration of the class InterfaceCrud
 ***********************************************************************/

#if !defined(__ClassProyecto_1_InterfaceCrud_h)
#define __ClassProyecto_1_InterfaceCrud_h

class InterfaceCrud
{
public:
   virtual void registrar(void)=0;
   virtual void eliminar(void)=0;
   virtual void consultar(void)=0;
   virtual void editar(void)=0;
   virtual void imprimir(void)=0;

protected:
private:

};

#endif