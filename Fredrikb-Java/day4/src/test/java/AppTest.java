/*
 * This Java source file was generated by the Gradle 'init' task.
 */
import org.junit.Test;
import se.droogies.bromaniac.adventofcode15.day4.App;

import static org.junit.Assert.assertEquals;

public class AppTest {
    @Test public void testAppHash() {
        App classUnderTest = new App();
        String myHash = classUnderTest.toHash("ILoveJava");
        assertEquals("35454B055CC325EA1AF2126E27707052", myHash.toUpperCase());
    }
}
