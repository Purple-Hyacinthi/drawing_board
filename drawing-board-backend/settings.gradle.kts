pluginManagement {
    repositories {
        gradlePluginPortal()
        mavenCentral()
    }
    plugins {
        id("org.springframework.boot") version "3.3.0"
        id("io.spring.dependency-management") version "1.1.5"
    }
}

rootProject.name = "drawing-board-backend"

include(
    ":application",
    ":user",
    ":canvas", 
    ":drawing",
    ":export"
)
