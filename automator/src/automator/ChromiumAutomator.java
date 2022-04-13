package automator;

import java.util.concurrent.TimeUnit;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;

public class ChromiumAutomator {
    public static void main(String[] args) throws Exception {
        System.setProperty("webdriver.chrome.driver", "/Users/lucas/privacy-activism/privacy-browser/Automator/resources/chromedriver");
        ChromeOptions options = new ChromeOptions();
        options.setBinary("/Users/lucas/privacy-activism/privacy-browser/chromium/src/out/Default/Chromium.app/Contents/MacOS/Chromium");
        WebDriver driver = new ChromeDriver(options);
        driver.get("https://my-location.org");

        for (int i=0; i < 5; i++) {
            driver.navigate().refresh();
            driver.manage().timeouts().implicitlyWait(8, TimeUnit.SECONDS);
        }

        //driver.close();
    }
}