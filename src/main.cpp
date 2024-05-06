#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv)
{
    SPDLOG_INFO("Start program");

    // glfw 라이브러리 초기화, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Initialize glfw");
    if (!glfwInit()) { // glfwInit를 통해 glfw를 초기화, 실패를 하게 되면 if문 안으로 들어감
        const char* description = nullptr;
        glfwGetError(&description); // 에러 사유를 description에 저장
        SPDLOG_ERROR("failed to initialize glfw: {}", description); // 타입을 정하지 않더라도 중괄호{} 로 묶어 둔 자리에 값이 들어가게 된다 
        return -1; // 실행 종료
    }

    // glfw 윈도우 생성, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Create glfw window");
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, // 윈도우 가로,세로 크기, 이름 지정, auto의 타입 = GLFWwindow*, auto는 C++11부터 사용가능
      nullptr, nullptr);
    if (!window) { // 실패하면 0, 성공하면 1 반환
        SPDLOG_ERROR("failed to create glfw window");
        glfwTerminate(); // glfw 라이브러리 종료
        return -1;
    }

    // glfw 무한루프 실행, 윈도우 close 버튼을 누르면 정상 종료
    SPDLOG_INFO("Start main loop");
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents(); // 윈도우 이벤트, 마우스 이벤트, 키보드 이벤트, 창 사이즈 변경 이벤트 등을 수집하는 역할
    }

    glfwTerminate();

    return 0;

    return 0;
}