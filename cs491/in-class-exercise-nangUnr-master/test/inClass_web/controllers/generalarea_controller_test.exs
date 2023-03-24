defmodule InClassWeb.GeneralareaControllerTest do
  use InClassWeb.ConnCase

  import InClass.CompanyFixtures

  @create_attrs %{name: "some name"}
  @update_attrs %{name: "some updated name"}
  @invalid_attrs %{name: nil}

  describe "index" do
    test "lists all generalareas", %{conn: conn} do
      conn = get(conn, Routes.generalarea_path(conn, :index))
      assert html_response(conn, 200) =~ "Listing Generalareas"
    end
  end

  describe "new generalarea" do
    test "renders form", %{conn: conn} do
      conn = get(conn, Routes.generalarea_path(conn, :new))
      assert html_response(conn, 200) =~ "New Generalarea"
    end
  end

  describe "create generalarea" do
    test "redirects to show when data is valid", %{conn: conn} do
      conn = post(conn, Routes.generalarea_path(conn, :create), generalarea: @create_attrs)

      assert %{id: id} = redirected_params(conn)
      assert redirected_to(conn) == Routes.generalarea_path(conn, :show, id)

      conn = get(conn, Routes.generalarea_path(conn, :show, id))
      assert html_response(conn, 200) =~ "Show Generalarea"
    end

    test "renders errors when data is invalid", %{conn: conn} do
      conn = post(conn, Routes.generalarea_path(conn, :create), generalarea: @invalid_attrs)
      assert html_response(conn, 200) =~ "New Generalarea"
    end
  end

  describe "edit generalarea" do
    setup [:create_generalarea]

    test "renders form for editing chosen generalarea", %{conn: conn, generalarea: generalarea} do
      conn = get(conn, Routes.generalarea_path(conn, :edit, generalarea))
      assert html_response(conn, 200) =~ "Edit Generalarea"
    end
  end

  describe "update generalarea" do
    setup [:create_generalarea]

    test "redirects when data is valid", %{conn: conn, generalarea: generalarea} do
      conn = put(conn, Routes.generalarea_path(conn, :update, generalarea), generalarea: @update_attrs)
      assert redirected_to(conn) == Routes.generalarea_path(conn, :show, generalarea)

      conn = get(conn, Routes.generalarea_path(conn, :show, generalarea))
      assert html_response(conn, 200) =~ "some updated name"
    end

    test "renders errors when data is invalid", %{conn: conn, generalarea: generalarea} do
      conn = put(conn, Routes.generalarea_path(conn, :update, generalarea), generalarea: @invalid_attrs)
      assert html_response(conn, 200) =~ "Edit Generalarea"
    end
  end

  describe "delete generalarea" do
    setup [:create_generalarea]

    test "deletes chosen generalarea", %{conn: conn, generalarea: generalarea} do
      conn = delete(conn, Routes.generalarea_path(conn, :delete, generalarea))
      assert redirected_to(conn) == Routes.generalarea_path(conn, :index)

      assert_error_sent 404, fn ->
        get(conn, Routes.generalarea_path(conn, :show, generalarea))
      end
    end
  end

  defp create_generalarea(_) do
    generalarea = generalarea_fixture()
    %{generalarea: generalarea}
  end
end
