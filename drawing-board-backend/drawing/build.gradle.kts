dependencies {
    implementation(project(":canvas"))
    implementation(project(":user"))

    implementation("org.springframework.boot:spring-boot-starter-web")
    implementation("org.springframework.boot:spring-boot-starter-security")
    implementation("org.springframework.boot:spring-boot-starter-data-jpa")
    implementation("org.springframework.boot:spring-boot-starter-validation")
    
    // 事件发布支持
    implementation("org.springframework:spring-context")
    
    // JSON处理
    implementation("com.fasterxml.jackson.core:jackson-databind")
    
    testImplementation("org.springframework.boot:spring-boot-starter-test")
}
