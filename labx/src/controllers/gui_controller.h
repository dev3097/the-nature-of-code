﻿
namespace nature_lab
{
    class gui_controller final : public interface_controller
    {
    public:
        static gui_controller* instance()
        {
            static gui_controller instance;
            return &instance;
        }

        gui_controller()
        {
        }
        
        void start() override;
        void update() override;
        void render() override;

        // void start(GLFWwindow* window, const std::string& version)
        // {
        //     const std::string glsl_version = "#version " + version + "0";
        //
        //     IMGUI_CHECKVERSION();
        //     ImGui::CreateContext();
        //     ImGuiIO& io = ImGui::GetIO();
        //     (void)io;
        //     io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        //     io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        //     io.ConfigFlags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;
        //
        //     ImGui::StyleColorsDark();
        //
        //     _window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
        //         ImGuiWindowFlags_NoCollapse |
        //         ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
        //         ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;
        //
        //     ImGuiStyle& style = ImGui::GetStyle();
        //     if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        //     {
        //         style.WindowRounding = 0.0f;
        //         style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        //     }
        //
        //     ImGui_ImplGlfw_InitForOpenGL(window, true);
        //     ImGui_ImplOpenGL3_Init(glsl_version.c_str());
        // }
        //
        // void update()
        // {
        // }
        //
        // void render()
        // {
        //     for (interface_gui*& inteface : controls_)
        //         inteface->render();
        // }
        //
        // void render(const int index) const
        // {
        //     if (controls_.empty())
        //         return;
        //     controls_[index]->render();
        // }
        //
        // void new_frame()
        // {
        //     ImGui_ImplOpenGL3_NewFrame();
        //     ImGui_ImplGlfw_NewFrame();
        //     ImGui::NewFrame();
        // }
        //
        // void end_frame() const
        // {
        //     ImGui::Render();
        //     ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        //
        //     ImGuiIO& io = ImGui::GetIO();
        //     (void)io;
        //
        //     if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        //     {
        //         GLFWwindow* backup_current_context = glfwGetCurrentContext();
        //         ImGui::UpdatePlatformWindows();
        //         ImGui::RenderPlatformWindowsDefault();
        //         glfwMakeContextCurrent(backup_current_context);
        //     }
        // }
        //
        //
        // void add_window(interface_gui* control)
        // {
        //     this->add_control(control);
        // }
        //
        // void add_control(interface_gui* control)
        // {
        //     this->controls_.push_back(control);
        // }


    private:
        // ImVec2 display_render_;
        // ImVec2 display_;

        // std::vector<interface_gui*> controls_;
        // ImGuiWindowFlags _window_flags{};
    };
}
