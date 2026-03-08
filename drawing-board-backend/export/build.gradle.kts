dependencies {
    implementation(project(":canvas"))
    implementation(project(":user"))

    implementation("org.springframework.boot:spring-boot-starter-web")
    implementation("org.springframework.boot:spring-boot-starter-security")
    implementation("org.springframework.boot:spring-boot-starter-data-jpa")
    
    // 图像处理
    implementation("org.apache.xmlgraphics:batik-all:1.17") // SVG支持
    implementation("com.twelvemonkeys.imageio:imageio-core:3.11.0") // 图像IO
    
    testImplementation("org.springframework.boot:spring-boot-starter-test")
}
