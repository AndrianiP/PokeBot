import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.UUID;
import java.util.Date;
import org.json.simple.J*;
//import org.json.simple.JSONObject;

public class DataWriter extends DataConstants {

    public static void saveAccounts() {
        ArrayList<Account> accountList = AccountList.getInstance().getAccounts();
        accountList.add(new User("gtaylor", "684651384"));
        accountList.add(new Admin("delta_admin", "54684316868"));
        
        JSONArray jsonAccounts = new JSONArray();

        for (int i = 0; i < accountList.size(); i++) {
            jsonAccounts.add(getAccountJSON(accountList.get(i)));
        }

        try (FileWriter file = new FileWriter(ACCOUNTS_FILE_NAME)) {
            file.write(jsonAccounts.toJSONString());
            file.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static JSONObject getAccountJSON(Account account) {
        JSONObject accountDetails = new JSONObject();
        accountDetails.put(ID, account.getID().toString());
        accountDetails.put(ACCT_TYPE, account.getType());
        accountDetails.put(USERNAME, account.getUsername());
        accountDetails.put(PASSWORD, account.getPassword());
        return accountDetails;
    }

    public static void saveFlights() {
        ArrayList<Flight> flightList = FlightList.getInstance().getFlights();
        flightList.add(new Flight(UUID.randomUUID(), new Date(), "ATL", "CF", Cities.ATLANTA, Country.searchForCountry("Georgia"), new Date(), "TUR", "3E", Cities.ISTANBUL, Country.searchForCountry("TURKEY"), Airlines.TURKISH_AIRLINES, "TA4513"));
        JSONArray jsonFlights = new JSONArray();

        for (int i = 0; i < flightList.size(); i++) {
            jsonFlights.add(getFlightJSON(flightList.get(i)));
        }

        try (FileWriter file = new FileWriter(FLIGHT_FILE_NAME)) {
            file.write(jsonFlights.toJSONString());
            file.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static JSONObject getFlightJSON(Flight flight) {
        JSONObject flightDetails = new JSONObject();
        flightDetails.put(FLIGHT_ID, flight.getID().toString());
        flightDetails.put(FLIGHT_DEPT_TIME, flight.getDeptTime());
        flightDetails.put(FLIGHT_DEPT_AIRP_CODE, flight.getDeptCode());
        flightDetails.put(FLIGHT_DEPT_GATE, flight.getDeptGate());
        flightDetails.put(FLIGHT_DEPT_CITY, flight.getDeptCity());
        flightDetails.put(FLIGHT_DEPT_COUNTRY, flight.getDeptCountry());
        flightDetails.put(FLIGHT_ARR_TIME, flight.getArrTime());
        flightDetails.put(FLIGHT_ARR_AIRP_CODE, flight.getArrCode());
        flightDetails.put(FLIGHT_ARR_GATE, flight.getArrGate());
        flightDetails.put(FLIGHT_ARR_CITY, flight.getArrCity());
        flightDetails.put(FLIGHT_ARR_COUNTRY, flight.getArrCountry());
        flightDetails.put(FLIGHT_AIRLINE, flight.getAirline());
        flightDetails.put(FLIGHT_NUM, flight.getFlightNumber());
        return flightDetails;
    }

    public static void saveHotels() {
        ArrayList<Hotel> hotelList = HotelList.getInstance().getHotels();
        JSONArray jsonHotels = new JSONArray();

        for (int i = 0; i < hotelList.size(); i++) {
            jsonHotels.add(getHotelJSON(hotelList.get(i)));
        }

        try (FileWriter file = new FileWriter(HOTEL_FILE_NAME)) {
            file.write(jsonHotels.toJSONString());
            file.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static JSONObject getHotelJSON(Hotel hotel) {
        JSONObject hotelDetails = new JSONObject();
        hotelDetails.put(HOTEL_ID, hotel.getID().toString());
        hotelDetails.put(HOTEL_COUNTRY, hotel.getCountry());
        hotelDetails.put(HOTEL_CITY, hotel.getCity());
        hotelDetails.put(HOTEL_ADDRESS, hotel.getAddress());
        hotelDetails.put(HOTEL_ZIP, hotel.getZip());
        return hotelDetails;
    }

    public static void saveRooms() {
        ArrayList<Room> roomList = RoomList.getInstance().getRooms();
        JSONArray jsonRooms = new JSONArray();

        for (int i = 0; i < roomList.size(); i++) {
            jsonRooms.add(getRoomsJSON(roomList.get(i)));
        }

        try (FileWriter file = new FileWriter(ROOM_FILE_NAME)) {
            file.write(jsonRooms.toJSONString());
            file.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static JSONObject getRoomsJSON(Room room) {
        JSONObject roomDetails = new JSONObject();
        roomDetails.put(ROOM_ID, room.getID().toString());
        roomDetails.put(ROOM_HOTEL_ID, room.getHotelID());
        roomDetails.put(ROOM_NUM_BEDS, room.getNumBeds());
        roomDetails.put(ROOM_NUM_BEDS, room.isAvailable());
        return roomDetails;
    }

    public static void saveCars() {
        ArrayList<Car> carList = CarList.getInstance().getCars();
        JSONArray jsonCars = new JSONArray();
        
        for (int i = 0; i < carList.size(); i++) {
            jsonCars.add(getCarsJSON(carList.get(i)));
        }

        try (FileWriter file = new FileWriter(CAR_FILE_NAME)) {
            file.write(jsonCars.toJSONString());
            file.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static JSONObject getCarsJSON(Car car) {
        JSONObject carDetails = new JSONObject();
        carDetails.put(CAR_ID, car.getID().toString());
        carDetails.put(CAR_MAKE, car.getMake());
        carDetails.put(CAR_TYPE, car.getCarType());
        carDetails.put(CAR_MODEL, car.getModel());
        carDetails.put(CAR_YEAR, car.getYear());
        carDetails.put(CAR_SEATS, car.getSeats());
        carDetails.put(CAR_COLOR, car.getColor());
        carDetails.put(ROOM_NUM_BEDS, car.getAvailability());
        return carDetails;
    }

    public static JSONObject getBookingsJSON(Booking booking) {
        JSONObject bookingDetails = new JSONObject();
        bookingDetails.put(BOOKING_ID, booking.getID().toString());
        bookingDetails.put(BOOKING_USER_ID, booking.getUser());
        bookingDetails.put(BOOKING_FLIGHT_ID, booking.getFlight());
        bookingDetails.put(BOOKING_HOTEL_ID, booking.getHotel());
        bookingDetails.put(BOOKING_ROOM_ID, booking.getRoom());
        bookingDetails.put(BOOKING_CAR_ID, booking.getCar());
        return bookingDetails;
    }
}
