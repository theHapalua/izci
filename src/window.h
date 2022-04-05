#ifndef APP_WINDOW
#define APP_WINDOW

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm.h>
#include <vector>

class AppWindow : public Gtk::Window{
	public:
		AppWindow();
		virtual ~AppWindow();
	protected:
	  // Main Widgets Container:
  	Gtk::Box m_Box;
  	Gtk::HeaderBar m_HeaderBar;
  	Gtk::StackSidebar m_StackSidebar;
  	Gtk::Separator m_Separator;
  	Gtk::Stack m_Stack;
    Gtk::Box s_Box;

    //Office Programs Page
    Gtk::Box OP_page;
    
    //Mİcrosoft Office
    Gtk::Expander MO_expander;
    Gtk::Box MO_box;
    Gtk::CheckButton LO_cbutton;

    //Page 2

    //Install
    void install();
    Gtk::Button i_button;
};

#endif
