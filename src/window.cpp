#include "window.h"
#include <gtkmm.h>
#include <iostream>

IzciWindow::IzciWindow(){
	set_title("deneme");
	button1.set_margin(10);
	button2.set_margin(10);
	Glib::ustring label = "Hello";
	button1.set_label(label);
	button2.set_label(label);
	button1.signal_clicked().connect(sigc::mem_fun(*this,&IzciWindow::on_button_clicked));
	button2.signal_clicked().connect(sigc::mem_fun(*this,&IzciWindow::on_button_clicked));
	box.append(button1);
	box.append(button2);
	box.set_margin_start(10);
	box.set_margin_end(250);
	box.set_margin_top(10);
	box.set_margin_bottom(230);
	this->set_default_size(500,300);
	this->set_child(box);

}

IzciWindow::~IzciWindow(){
}

void IzciWindow::on_button_clicked(){

std::cout << "Hello World\n";
}
