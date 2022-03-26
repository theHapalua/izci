#ifndef IZCI_WINDOW
#define IZCI_WINDOW

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm.h>

class IzciWindow : public Gtk::Window{
	public:
		IzciWindow();
		virtual ~IzciWindow();
	protected:
		void on_button_clicked();
		Gtk::Button button1;
		Gtk::Button button2;
		Gtk::Box box = Gtk::Box(Gtk::Orientation::VERTICAL);

};

#endif
