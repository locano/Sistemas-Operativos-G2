create user 'pfinal' identified by 'pfinal';
create schema lista_transaccion;
grant all privileges on lista_transaccion.* to 'pfinal';
use lista_transaccion;
create table lista_transaccion (
	
    id integer AUTO_INCREMENT primary key,
    origen  varchar(5) not null,
    destino varchar(5)  not null
    

);
