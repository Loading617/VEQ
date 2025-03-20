#include <gtkmm.h>
#include <vector>
#include <string>

class Equalizer : public Gtk::Window {
public:
    Equalizer();
    virtual ~Equalizer() {}

private:
    void on_slider_value_changed();
    void on_preset_selected();
    void on_profile_selected();
    
    Gtk::Box m_vbox;
    Gtk::Label m_title;
    std::vector<Gtk::Scale*> m_sliders;
    Gtk::Button m_reset_button;
    Gtk::ComboBoxText m_preset_selector;
    Gtk::ComboBoxText m_profile_selector;
};

Equalizer::Equalizer()
    : m_vbox(Gtk::Orientation::VERTICAL), m_title("VEQ"), m_reset_button("Reset") {
    set_title("VEQ");
    set_default_size(400, 300);
    set_child(m_vbox);
    
    m_title.set_margin(10);
    m_vbox.append(m_title);
    
    std::vector<std::string> bands = {"60Hz", "170Hz", "310Hz", "600Hz", "1kHz", "3kHz", "6kHz", "12kHz", "14kHz", "16kHz"};
    for (const auto& band : bands) {
        Gtk::Box* hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL);
        Gtk::Label* label = Gtk::make_managed<Gtk::Label>(band);
        Gtk::Scale* slider = Gtk::make_managed<Gtk::Scale>(Gtk::Adjustment::create(0, -12, 12, 1), Gtk::Orientation::VERTICAL);
        slider->set_inverted();
        slider->set_margin(5);
        slider->set_digits(0);
        slider->set_round_digits(0);
        slider->set_value_pos(Gtk::PositionType::TOP);
        slider->signal_value_changed().connect(sigc::mem_fun(*this, &Equalizer::on_slider_value_changed));
        
        hbox->append(*label);
        hbox->append(*slider);
        m_sliders.push_back(slider);
        m_vbox.append(*hbox);
    }
    m_preset_selector.append("Default");
    m_preset_selector.append("Action");
    m_preset_selector.append("Drama");
    m_preset_selector.append("Horror");
    m_preset_selector.append("Music");
    m_preset_selector.append("Movie");
    m_preset_selector.append("Comedy");
    m_preset_selector.append("Sci-Fi");
    m_preset_selector.append("Thriller");
    m_preset_selector.append("Fantasy");
    m_preset_selector.append("Romance");
    m_preset_selector.append("Western");
    m_preset_selector.append("Animation");
    m_preset_selector.append("Crime");
    m_preset_selector.append("Romantic Comedy");
    m_preset_selector.append("Adventure");
    m_preset_selector.append("Documentary");
    m_preset_selector.append("Historical");
    m_preset_selector.append("Sports");
    m_preset_selector.append("Video");
    m_preset_selector.append("AV Receiver");
    m_preset_selector.append("Soundbar");
    m_preset_selector.append("Computer Speakers");
    m_preset_selector.append("3D 1");
    m_preset_selector.append("3D 2");
    m_preset_selector.append("3D 3");
    m_preset_selector.append("Cinema 1");
    m_preset_selector.append("Cinema 2");
    m_preset_selector.append("Cinema 3");
    m_preset_selector.append("Surround 1");
    m_preset_selector.append("Surround 2");
    m_preset_selector.append("Surround 3");
    m_preset_selector.append("Home Theater 1");
    m_preset_selector.append("Home Theater 2");
    m_preset_selector.append("Home Theater 3");
    m_preset_selector.append("Voice 1");
    m_preset_selector.append("Voice 2");
    m_preset_selector.append("Voice 3");
    m_preset_selector.append("Game 1");
    m_preset_selector.append("Game 2");
    m_preset_selector.append("Game 3");
    m_preset_selector.set_active(0);
    m_preset_selector.signal_changed().connect(sigc::mem_fun(*this, &Equalizer::on_preset_selected));
    m_vbox.append(m_preset_selector);

    m_profile_selector.append("User 1");
    m_profile_selector.append("User 2");
    m_profile_selector.append("User 3");
    m_profile_selector.set_active(0);
    m_profile_selector.signal_changed().connect(sigc::mem_fun(*this, &Equalizer::on_profile_selected));
    m_vbox.append(m_profile_selector);

    m_reset_button.set_margin(10);
    m_reset_button.signal_clicked().connect([this] {
        for (auto slider : m_sliders) {
            slider->set_value(0);
        }
    });
    m_vbox.append(m_reset_button);
}

void Equalizer::on_slider_value_changed() {
}

void Equalizer::on_preset_selected() {
    std::string preset = m_preset_selector.get_active_text();
    if (preset == "Action") {
        std::vector<int> values = {3, 4, 5, 3, 2, -1, -2, -3, -4, -5};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Drama") {
        std::vector<int> values = {2, 3, 4, 3, 2, 1, -1, -2, -3, -4};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Horror") {
        std::vector<int> values = {-2, -3, -4, -3, -2, -1, 1, 2, 3, 4};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Music") {
        std::vector<int> values = {5, 4, 3, 2, 1, 0, -1, -2, -3, -4};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Movie") {
        std::vector<int> values = {4, 3, 2, 1, 0, -1, -2, -3, -4, -5};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Comedy") {
        std::vector<int> values = {3, 2, 1, 0, -1, -2, -3, -4, -5, -6};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Sci-Fi") {
        std::vector<int> values = {6, 5, 4, 3, 2, 1, 0, -1, -2, -3};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Thriller") {
        std::vector<int> values = {5, 4, 3, 2, 1, 0, -1, -2, -3, -4};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Fantasy") {
        std::vector<int> values = {+2, +1, -1, -2, +2, +3, +4, +5, +4, +3};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Romance") {
        std::vector<int> values = {+3, +2, +1, 0, +2, +1, +2, +1, 0, +1};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Western") {
        std::vector<int> values = {4, 3, 2, 1, 0, -1, -2, -3, -4, -5};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Animation") {
        std::vector<int> values = {3, 2, 1, 0, -1, -2, -3, -4, -5, -6};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Crime") {
        std::vector<int> values = {6, 5, 4, 3, 2, 1, 0, -1, -2, -3};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Romantic Comedy") {
        std::vector<int> values = {3, 4, 5, 3, 2, -1, -2, -3, -4, -5};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Adventure") {
        std::vector<int> values = {+4, +3, +2, 0, +2, +3, +4, +3, +2, +2};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Documentary") {
        std::vector<int> values = {5, 4, 3, 2, 1, 0, -1, -2, -3, -4};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Historical") {
        std::vector<int> values = {4, 3, 2, 1, 0, -1, -2, -3, -4, -5};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Sports") {
        std::vector<int> values = {+5, +4, +2, +1, +2, +3, +4, +1, +2, +3};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Video") {
        std::vector<int> values = {+3, +2, +1, 0, +3, +2, +3, +2, +1, 0};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "AV Receiver") {
        std::vector<int> values = {+3, +2, +1, 0, +2, +3, +3, +2, +1, 0};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Soundbar") {
        std::vector<int> values = {+4, +3, +1, 0, +3, +4, +3, +2, +1, 0};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Computer Speakers") {
        std::vector<int> values = {+5, +3, +2, 0, +3, +4, +3, +2, +1, 0};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "3D 1") {
        std::vector<int> values = {+3, +2, 0, -1, +2, +4, +5, +4, +3, +2};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
                m_sliders[i]->set_value(values[i]);
            }
    } else if (preset == "3D 2") {
        std::vector<int> values = {+4, +3, +2, 0, +1, +4, +6, +5, +4, +5};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "3D 3") {
        std::vector<int> values = {+5, +4, +3, +1, +2, +5, +7, +6, +5, +6};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Cinema 1") {
        std::vector<int> values = {+6, +4, +2, +1, +3, +6, +5, +6, +4, +5};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Cinema 2") {
        std::vector<int> values = {+7, +5, +4, +2, +3, +7, +6, +7, +6, +7};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Cinema 3") {
        std::vector<int> values = {+8, +6, +5, +3, +4, +8, +7, +8, +7, +8};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Surround 1") {
        std::vector<int> values = {+6, +5, +4, +2, +3, +6, +7, +6, +5, +7};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Surround 2") {
        std::vector<int> values = {+5, +4, +3, +2, +3, +7, +8, +7, +6, +8};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Surround 3") {
        std::vector<int> values = {+7, +5, +4, +3, +4, +8, +9, +8, +7, +9};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Home Theater 1") {
        std::vector<int> values = {+6, +5, +4, +3, +4, +6, +7, +6, +5, +6};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Home Theater 2") {
        std::vector<int> values = {+7, +6, +5, +4, +4, +6, +8, +7, +6, +7};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
                m_sliders[i]->set_value(values[i]);
            }
    } else if (preset == "Home Theater 3") {
        std::vector<int> values = {+8, +6, +5, +4, +4, +7, +9, +8, +7, +9};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Voice 1") {
        std::vector<int> values = {-3, -2, 0, +2, +5, +6, +5, +4, +3, +3};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Voice 2") {
        std::vector<int> values = {-4, -2, +1, +3, +6, +7, +6, +5, +4, +4};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Voice 3") {
        std::vector<int> values = {-5, -3, +1, +4, +7, +8, +7, +6, +5, +5};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Game 1") {
        std::vector<int> values = {+6, +4, +3, +2, +4, +7, +6, +5, +4, +6};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Game 2") {
        std::vector<int> values = {+7, +5, +4, +3, +5, +8, +7, +6, +5, +7};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
            m_sliders[i]->set_value(values[i]);
        }
    } else if (preset == "Game 3") {
        std::vector<int> values = {+8, +6, +5, +4, +5, +9, +8, +7, +6, +8};
        for (size_t i = 0; i < m_sliders.size(); ++i) {
                m_sliders[i]->set_value(values[i]);
            }
    } else {
        for (auto slider : m_sliders) {
            slider->set_value(0);
        }
    }
}

void Equalizer::on_profile_selected() {
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.example.equalizer");
    return app->make_window_and_run<Equalizer>(argc, argv);
}
